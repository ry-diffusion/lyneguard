#include "../shared/kcl.h"
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/processor.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ryster Diffusion");
MODULE_DESCRIPTION("Lyne Guard");

void kcl_log_info(const char *content) { printk("%s%s", KERN_INFO, content); }

static char *readFile(const char *restrict path, loff_t *read) {
  char *output = NULL;
  loff_t size = 0;
  struct file *file = NULL;

  file = filp_open(path, O_RDONLY, 0);
  if (IS_ERR(file)) {
    printk(KERN_ERR "lyneguard: unable to open the %s!\n", path);
    return NULL;
  }

  size = i_size_read(file->f_inode);

  output = kmalloc(size + 1, GFP_KERNEL); // Allocate space for null terminator
  if (!output) {
    printk(KERN_ERR "lyneguard: out of memory");
    goto out_close;
  }

  *read = kernel_read(file, output, size, &file->f_pos);
  if (*read < 0) {
    printk(KERN_ERR "lyneguard: unable to read file");
    goto out_free;
  }

  // Null terminate the string
  output[*read] = '\0';

out_free:
  if (*read < 0) {
    kfree(output);
    output = NULL;
  }

out_close:
  filp_close(file, NULL);
  return output;
}

static int __init lyne_kmod_init(void) {
  loff_t size = 0;

  char *output = readFile("/test.txt", &size);
  printk(KERN_INFO "lyneguard: output=%s endoutput size=%lld", output, size);
  kfree(output);
  return 0;
}

static void __exit lyne_kmod_bye(void) {}

module_init(lyne_kmod_init);
module_exit(lyne_kmod_bye);

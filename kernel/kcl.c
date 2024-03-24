#include "kcl.h"
#include "linux/fs.h"
#include "linux/types.h"
#include "linux/uaccess.h"
#include <linux/device.h>
#include <linux/device/class.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/slab.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 2, 0)
#define KClassCreate(x) class_create(THIS_MODULE, x)
#else
#define KClassCreate class_create
#endif

void kcl_log_info(str content) { printk("%s%s", KERN_INFO, content); }

int kcl_alloc_device(KMajor major, str name,
                     unique(IoOperations) ioOperations) {
  struct file_operations *fops;

  ioOperations->kInformation =
      kmalloc(sizeof(struct file_operations), GFP_KERNEL);

 
  fops =
      (struct file_operations *)ioOperations->kInformation;

  fops->unlocked_ioctl = (long (*)(struct file *, Uint32 cmd, Uint64 arg))(
                             void *)ioOperations->IOControl;

  return register_chrdev(major, name, ioOperations->kInformation);
}

void kcl_dealloc_device(KMajor major, str name,
                        unique(IoOperations) ioOperations) {
  unregister_chrdev(major, name);

  kfree(ioOperations->kInformation);
}

KDevice kcl_register_device(KClass deviceClass, KMajor major, str deviceName) {
  return device_create(deviceClass, NULL, MKDEV(major, 0), NULL, deviceName);
}

void kcl_drop_device(KClass deviceClass, KMajor major) {
  device_destroy(deviceClass, MKDEV(major, 0));
}

KClass kcl_register_class(str name) { return KClassCreate(name); }
void kcl_drop_class(KClass class) {
  class_unregister(class);
  class_destroy(class);
}

int kcl_touser(void *arg, const void *value, Uint64 size) {
  return copy_to_user(arg, value, size);
}

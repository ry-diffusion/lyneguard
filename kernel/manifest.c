#include "lyne.h"
#include <linux/init.h>
#include <linux/module.h>

static int __init lyne_kmod_init(void) {
  lyne_init();
  return 0;
}

static void __exit lyne_kmod_bye(void) {}

module_init(lyne_kmod_init);
module_exit(lyne_kmod_bye);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ryster Diffusion");
MODULE_DESCRIPTION("Lyne Guard");

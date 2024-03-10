#include <linux/module.h>

void kcl_log_info(const char *content) { printk("%s%s", KERN_INFO, content); }

#include "lyneguard.h"
#include "kcl.h"
#include "lyne_defs.h"

KClass lyneguardClass;
KMajor major;

unsigned int lyne_init(void) {
  kcl_log_info("lyneguard: Hello world from module!");

  lyneguardClass = kcl_register_class("LyneGuard");

  if (lyneguardClass < 0) {
    kcl_log_info("lyneguard: unable to register lyne control class!");
    return -1;
  }

  if ((major = kcl_alloc_device(0, LYNEGUARD_CTRL_NAME,
                                &lyneDeviceOperations)) < 0) {
    kcl_drop_class(lyneguardClass);
    kcl_log_info("lyneguard: unable to register lyne control file.");
    return -1;
  }

  kcl_register_device(lyneguardClass, major, LYNEGUARD_CTRL_NAME);

  return 0;
}

void lyne_exit(void) {
  kcl_log_info("lyneguard: deinitializing module");
  kcl_drop_device(lyneguardClass, major);

  kcl_dealloc_device(0, LYNEGUARD_CTRL_NAME, &lyneDeviceOperations);
  kcl_drop_class(lyneguardClass);
}

#include "ioctl_defs.h"
#include "kcl.h"
#include "lyne_defs.h"
#include "lyneguard.h"

long lyne_control_io_control(KFile file, Uint32 cmd, KPtr arg) {

  if (cmd == IOCTL_LYNE_QUERYSTATUS) {
    kcl_log_info("lyneguard: getting status...\n");
    int xd = 69;
    kcl_touser((int *)arg, &xd, sizeof(int));
    return 0;
  }

  return -1;
}

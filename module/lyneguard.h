#pragma once
#include "types.h"
#include <kcl.h>

long lyne_control_io_control(KFile file, Uint32 cmd, KPtr arg);

static IoOperations lyneDeviceOperations = {
    .IOControl = lyne_control_io_control, .kInformation = 0};

const static str LYNEGUARD_CTRL_NAME = "lyneguard-control";

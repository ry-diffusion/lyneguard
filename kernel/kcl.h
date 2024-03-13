#pragma once

#include "types.h"

typedef unsigned long KPtr;
typedef void *KFile;
typedef void *KClass;
typedef void *KDevice;
typedef unsigned int KMajor;

/**
 * @brief Log a information
 */
void kcl_log_info(str content);

typedef struct IOOperations {
  long (*IOControl)(KFile file, Uint32 cmd, KPtr arg);

  void *kInformation;
} IoOperations;

int kcl_alloc_device(KMajor major, str name, unique(IoOperations) ioOperations);
void kcl_dealloc_device(KMajor major, str name,
                        unique(IoOperations) ioOperations);

KDevice kcl_register_device(KClass deviceClass, KMajor major, str deviceName);
void kcl_drop_device(KClass deviceClass, KMajor major);

int kcl_touser(void *arg, const void *value, Uint64 size);

KClass kcl_register_class(str name);
void kcl_drop_class(KClass class);

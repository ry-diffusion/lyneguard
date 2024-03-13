obj-m += lyneguard.o
BUILD_PROFILE ?= debug
PWD = $(shell pwd)

LYNEGUARD ?= lyneguard_blob.o

lyneguard-objs := manifest.o kcl.o ioctl_defs.o $(LYNEGUARD)

KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: lyneguard.ko

lyneguard.ko: 
	$(MAKE) -C $(KDIR) M=$(PWD) SRCDIR=$(PWD) modules

$(SRCDIR)/$(LYNEGUARD):
$(LYNEGUARD):

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

CONFIG_MODULE_SIG=n

obj-m       += lyneguard.o
LYNEGUARD   ?= lgcombined.o
lyneguard-y := manifest.o kcl.o ioctl_defs.o $(LYNEGUARD)
SRCDIR      ?= $(shell pwd)

KDIR ?= /lib/modules/$(shell uname -r)/build

.PHONY: lyneguard.ko

lyneguard.ko: .$(SRCDIR)/$(LYNEGUARD).cmd
	$(MAKE) -C $(KDIR) M=$$PWD SRCDIR=$$PWD modules

.$(SRCDIR)/$(LYNEGUARD).cmd:
	echo > $(SRCDIR)/.$(LYNEGUARD).cmd

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean 
	rm *_shipped

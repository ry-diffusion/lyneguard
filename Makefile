.PHONY: module kernel

kernel: module
	cp module/lyne_combined.o kernel/lgcombined.o_shipped
	make -C kernel LYNEGUARD=lgcombined.o lyneguard.ko

module:
	make -C module

clean:
	make -C module clean
	make -C kernel clean

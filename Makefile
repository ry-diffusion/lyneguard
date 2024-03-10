.PHONY: module kernel

kernel: module
	cp module/build/liblyneguard.a kernel/liblyneguard.a
	make -C kernel LYNEGUARD=liblyneguard.a lyneguard.ko

module:
	cd module; 	cmake -B build; cmake --build build

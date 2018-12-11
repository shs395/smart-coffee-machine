KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := button_dev.o

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	sudo insmod button_dev.ko
	sudo mknod -m 666 /dev/button_dev c 240 0

clean:
	rm button_dev.o button_dev.ko button_dev.mod.c button_dev.mod.o modules.order Module.symvers
	sudo rm /dev/button_dev
	sudo rmmod button_dev.ko

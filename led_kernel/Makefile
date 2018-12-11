KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := led_dev.o

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	sudo insmod led_dev.ko
	sudo mknod -m 666 /dev/led_dev c 290 0

clean:
	rm led_dev.o led_dev.ko led_dev.mod.c led_dev.mod.o modules.order Module.symvers
	sudo rm /dev/led_dev
	sudo rmmod led_dev

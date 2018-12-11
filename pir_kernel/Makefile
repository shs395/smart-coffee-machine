KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := pir_dev.o

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	sudo insmod pir_dev.ko
	sudo mknod -m 666 /dev/pir_sensor c 280 0

clean:
	rm pir_dev.o pir_dev.ko pir_dev.mod.c pir_dev.mod.o modules.order Module.symvers
	sudo rm /dev/pir_sensor
	sudo rmmod pir_dev

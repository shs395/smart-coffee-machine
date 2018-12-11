KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := buzzer_dev.o

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	sudo insmod buzzer_dev.ko
	sudo mknod -m 666 /dev/buzzer_dev c 243 0

clean:
	rm buzzer_dev.o buzzer_dev.ko buzzer_dev.mod.c buzzer_dev.mod.o modules.order Module.symvers
	sudo rm /dev/buzzer_dev
	sudo rmmod buzzer_dev.ko

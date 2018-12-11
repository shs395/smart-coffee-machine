#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/kdev_t.h>
#include "led.h"

#define DEV_PATH "/dev/led_dev"

int led(){
	int fd =0;
	if((fd = open(DEV_PATH,O_RDWR))<0){
		perror("open()");
		exit(1);
	}
	sleep(3);
	close(fd);
	return 0;
}


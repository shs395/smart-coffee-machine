#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "buzzer.h"

#define BUZZER_PATH "/dev/buzzer_dev"

int buzzer(int receive) 
{
	int fd, wd;

	if((fd = open(BUZZER_PATH, O_RDWR))<0){
		perror("open()");
		exit(1);
	}
	printf("Buzzer open success");
	if((wd = write(fd, &receive,sizeof(receive)))<0){
		perror("Faile to write the contents");
		exit(1);
	}
	close(fd);
	return 0;
}


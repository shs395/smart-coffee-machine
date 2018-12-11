#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "sp_pir_app.h"

#define DEVICE_FILE "/dev/pir_sensor"

int pir() {
	int fd, buffer;

	fd = open(DEVICE_FILE, O_RDWR);
	
	if(read(fd, &buffer, sizeof(buffer)) != 0) {
		printf("PIR_ERROR");
		return -1;
	}
	
	printf("%d\n", buffer);
	close(fd);

	return buffer;
}



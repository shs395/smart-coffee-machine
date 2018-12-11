#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "button.h"

int button()
{
	int ret, receive, fd;

	fd = open("/dev/button_dev", O_RDWR);
	if(fd < 0){
		perror("Failed to open the device...");
		return errno;
	}
	
	ret = read(fd, &receive, sizeof(receive));
	if (ret < 0) {
		perror("Failed to read the message from the device.");
		return errno;
	}

	close(fd);

	return receive;
}
	

#include "header.h"

int main(){

int fd,running = 1, ret;
char buf[MAX_BUF];

/* open, read, and display the message from the FIFO */
fd = open(FIFO_PATH, O_RDONLY);
while(running){
	ret = read(fd, buf, MAX_BUF);
	printf("Received: %s\n", buf);

	if(strncmp(buf,"bye",ret)==0){
		running = 0;
	}
}
close(fd);

return 0;
}
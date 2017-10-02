#include "header.h"

int main(int argc, char *argv[]){
	int fd,running=1;
	char buff[256];

    /* create the FIFO (named pipe) */
    mkfifo(FIFO_PATH, 0666);

    /* write "Hi" to the FIFO */
    fd = open(FIFO_PATH, O_WRONLY);
    while(running){
    	fgets(buff,256,stdin);
    	if(strncmp(buff,"bye",3)!=0){
    		write(fd, buff, sizeof(buff));
    	}
    	else{
    		running = 0;
    	}
	}
    close(fd);

    /* remove the FIFO */
    unlink(FIFO_PATH);

    return 0;
}
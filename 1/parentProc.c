#include "header.h"

char* msg1 = "Hello1";
char* msg2 = "Hello2";
char* msg3 = "Hello3";

int main(int argc, char *argv[]){
	pid_t pid;
	int pipeFd[2],retByte;
	char inBuff[6];

	if(pipe(pipeFd)<0){
		perror("Error in pipe");
	}

	if((pid = fork())==0){
		//child which will read from the pipe
		while((retByte = read(pipeFd[0],inBuff,sizeof(inBuff)))>0){
			printf("%s \n",inBuff);
		}
		if (retByte != 0) exit(2);

		printf("\n\n finished reading from the pipe \n");
	}
	else{
		//parent process which will write to the pipe
		write(pipeFd[1],msg1,strlen(msg1));
		write(pipeFd[1],msg2,strlen(msg2));
		write(pipeFd[1],msg3,strlen(msg3));
		//after writing parent will sleep for 5 seconds
		sleep(5);
	}

}
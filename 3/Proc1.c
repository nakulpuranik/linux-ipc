#include "header.h"

int main(int argc, char *argv[]){
    pid_t pid;
    int pipeFd[2],retByte,index;
    char inBuff[256]={'\n'};

    if(pipe(pipeFd)<0){
        perror("Error in pipe");
    }

    if((pid = fork())==0){
        int dupWr;
        dupWr = dup(pipeFd[1]);
        close(pipeFd[0]);
        close(pipeFd[1]);
    
        printf("Child will start wrinting in pipe\n");
        strcpy(inBuff,argv[1]);
        write(dupWr,inBuff,strlen(inBuff));
        printf("finished writing from the pipe \n");
        
        //_exit(1);
    }
    else{
        //parent process which will read from the pipe
        int ret,dupFd;

        dupFd = dup(pipeFd[0]);
        close(pipeFd[1]);
        close(pipeFd[0]);
        printf("Parent started reading from pipe\n");
        while((ret=read(dupFd,inBuff,strlen(inBuff)))!=0){
           //write(1,inBuff,ret);
            printf("%s",inBuff);
        }
        printf("\nParent finished reading from pipe\n");
    }
    return 0;
}
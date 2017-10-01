#include "header.h"

int main(int argc, char *argv[]){
	
	char c;
    int shmid;
    key_t key;
    char *shm, *charPtr;

    key = ftok(".",0);
    printf("Using key %u\n",(unsigned int)key);

    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    shm = shmat(shmid, NULL, 0);
    charPtr = shm;

    for (c = 'a'; c <= 'z'; c++)
	{
    	*charPtr = c;
		charPtr++;	
	}
	*charPtr = NULL;
	printf("Data writtent to shared memory \n Now waiting for child... \n");
    

    while (*shm != '*'){
        sleep(1);
    }

    printf("Confirmation received from child. Closing now...\n");
    exit(0);
}
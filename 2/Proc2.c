#include "header.h"

int main(int argc, char *argv[]){
	
	char c;
    int shmid;
    key_t key;
    char *shm, *charPtr;

    key = ftok(".",0);
    printf("Using key %u\n",(unsigned int)key);

    shmid = shmget(key, SHMSIZE, 0666);

    shm = shmat(shmid, NULL, 0);
    
    for (charPtr = shm; *charPtr != NULL; charPtr++)
	{
        putchar(*charPtr);
	}
    putchar('\n');

    *shm = '*';

    exit(0);
}
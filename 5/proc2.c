#include "header.h"

struct my_msg_st
{
	long int my_msg_type;
	char some_text[MAX_TEXT];
};

int main(){

	int running = 1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[MAX_TEXT];
	key_t key;

	key = ftok(".",0);
	msgid = msgget( key, IPC_CREAT | 0666);

	if (msgid == -1){
		exit(-1);
	}
	while(running){
		printf("Enter Some Text: ");
		fgets(buffer, MAX_TEXT, stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text, buffer);

		if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1){
			fprintf(stderr, "msgsnd failed\n");
			exit(-1);
		}
		if(strncmp(buffer, "bye", 3) == 0){
			running = 0;
		}
	}
	exit(0);
}
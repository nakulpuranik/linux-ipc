#include "header.h"

struct my_proc1_msg
{
	long int msg_id;
	char msg_txt[BUFSIZ];
};

int main(int argc, char *argv[]){

	int running = 1;
	int msgid;
	struct my_proc1_msg msg_data;
	long int msg_to_receive = 0;
	key_t key;

	key = ftok(".",0);
	msgid = msgget( key, 0666 | IPC_CREAT);

	while (running){

		if(msgrcv(msgid, (void*)&msg_data,BUFSIZ,msg_to_receive,0) < 0){
			perror("Error receiving msg");
			exit(1);
		}

		if(strlen(msg_data.msg_txt) > 0){
			printf("\nYou Wrote: %s", msg_data.msg_txt);
		}
		if(strncmp(msg_data.msg_txt, "bye", 3)== 0){
			running = 0;
		}
		sleep(1);
	}

	exit(0);
}
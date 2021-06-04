#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>


struct message {
	long mtype;
	
	char text[100];
}msgwrite;


int main() {

	int key, msgq_id;
	// creating a token
	key = ftok(".", 1);
	//perror("ftok: ");

	// creating a msgq & getting the msgq_id
	msgq_id = msgget(key, IPC_CREAT);
	//perror("msgget: ");

	// Fill the msg struct
	msgwrite.mtype = 200;
	strcpy(msgwrite.text, " Message with type value 200\n");

	// send the msg to the msgq
	msgsnd(msgq_id, (void *)&msgwrite, sizeof(msgwrite), IPC_NOWAIT);
	//perror("msgsnd: ");


	return 0;

}

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>


struct message {
	long mtype;

	char text[100];

}msgread;

int main() {

	int key, msgq_id;

	key = ftok(".", 1 );
	//perror("ftok :");

	msgq_id = msgget(key, 0);
	//perror("msgget :");

	msgrcv(msgq_id, (void *)&msgread, sizeof(msgread), 200, IPC_NOWAIT);
	//perror("msgrcv :");

	printf("%s \n", msgread.text);

	// To remove the message queue
	msgctl(msgq_id, IPC_RMID, (struct msqid_ds *) NULL);


	return 0;
}

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void handler(int sig) {

	int status;

	printf(" signal handler \n");
	wait(&status);
	
	getchar();

}

int main() {

	int pid;

	signal(SIGCHLD, handler);

	pid = fork();

	if(pid!=-1 && pid==0) {
		printf(" This is child process \n");
	}

	if(pid!=-1 && pid!=0) {
		printf(" Parent process \n");
		sleep(20);
	}

	return 0;

}

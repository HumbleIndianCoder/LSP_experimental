#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void handler(int signum) {

	printf(" Handler \n");

}

int main() {

	int pid;

	signal(SIGINT, handler);

	char *argv[] = {"cat", "/usr/include/asm-generic/signal.h", NULL};	
	pid = fork();

	if(pid!=-1 && pid==0) {
		printf(" This is child process = %d\n",getpid());
		//execvp(argv[0], argv); //  loads new binary
		execl("getchar", "getchar", NULL);
		getchar();
	}

	if(pid!=-1 && pid!=0) {
		printf(" This is parent process with pid=%d\n", getpid());
		getchar();
	}



	return 0;

}

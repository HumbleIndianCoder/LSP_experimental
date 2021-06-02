#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void sighandler(int signum) {
	printf("We are in the sig handler and the received signal is %s \n", sys_siglist[signum]);

}

int main() {

	int pid, status;

	signal(SIGINT, SIG_IGN);
	signal(SIGCHLD, sighandler);

	pid=fork();


	if(pid!=-1 && pid==0) {
		printf(" Child process \n");
	}

	if(pid!=-1 && pid!=0) {
		printf(" Parent process \n");
		sleep(20);
		wait(&status);
	}



	getchar();

	return 0;

}

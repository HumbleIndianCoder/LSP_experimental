#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>


int main() {

	int pid, status;

	pid=fork();

	if(pid!=-1 && pid==0) {
		printf("In the child process with pid = %d\n", getpid());
		getchar();
	}

	if(pid!=-1 && pid!=0) {
		kill(pid, SIGKILL); // to kill the child
		wait(&status);
	}

	return 0;

}

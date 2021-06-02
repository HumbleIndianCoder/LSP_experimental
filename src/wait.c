#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>


int main() {

	int pid1, pid2, status, pid_child;

	pid1 = fork();

	if(pid1!=-1 && pid1==0) {
		printf(" Child Process \n");
		getchar();
	}

	if(pid1!=-1 && pid1!=0) {
		printf(" Parent process \n");
		pid2 = fork();

		if(pid2!=-1 && pid2==0) {
			printf(" Second child \n");
			getchar();
		}

		if(pid2!=-1 && pid2!=0) {
			pid_child = wait(&status);
			printf(" Successfully gathered the status of %d\n", pid_child);
			if(WIFEXITED(status))
				printf("Normal termination\n");
			if(WIFSIGNALED(status))
				printf("Terminated by signal\n");
		}
	}



	return 0;

}

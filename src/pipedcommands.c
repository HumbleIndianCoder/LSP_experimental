#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int main() {


	int pipefd[2], pid1, pid2, status;
	char *argv1[] = {"cat","/usr/include/asm-generic/errno.h", NULL};
	char *argv2[] = {"less", NULL};


	pipe(pipefd);

	pid1=fork();

	if(pid1==0 && pid1!=-1) {

		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);

		execvp(argv1[0], argv1);


	}

	if(pid1!=0 && pid1!=-1) {

		pid2 = fork();

		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);

		execvp(argv2[0], argv2);


	}


	waitpid(pid1, &status,  0);
	waitpid(pid2, &status,  0);

	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define Read 0
#define Write 1

char *message = "One Child process is writing into the pipe & other child  process is reading it";

int main() {

	int fd[2], pid1, pid2, bytesread, byteswritten;
	char readmessage[100];
	// create a pipe 
	pipe(fd);

	pid1 = fork();

	if(pid1!=-1 && pid1==0) {

		close(fd[Read]);
		byteswritten = write(fd[Write], message, strlen(message)+1);

	}
	if(pid1!=-1 && pid1!=0) {

		pid2 = fork();

		if(pid2!=-1 && pid2==0) {

			close(fd[Write]);
			bytesread = read(fd[Read], readmessage, 100);
			printf(" The message read from the pipe is :\n %s \n and its length is %d\n", readmessage, bytesread);
		}


		if(pid2!=-1 && pid2!=0) {
			getchar();
			// wait(&status);
		}

	}


	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define Read 0
#define Write 1

char *message = "Child process is writing into the pipe & parent process is reading it";

int main() {

	int fd[2], pid, bytesread, byteswritten;
	char readmessage[100];

	// create a pipe 
	pipe(fd);

	pid = fork();

	if(pid!=-1 && pid==0) {

		close(fd[Read]);
		byteswritten = write(fd[Write], message, strlen(message)+1);

	}


	if(pid!=-1 && pid!=0) {

		close(fd[Write]);
		bytesread = read(fd[Read], readmessage, 100);
		printf(" The message read from the pipe is :\n %s \n and its length is %d\n", readmessage, bytesread);
	}


	return 0;
}

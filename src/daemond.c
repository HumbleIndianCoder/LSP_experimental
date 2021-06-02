#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main() {

	int pid;
	FILE *fp = NULL;

	/* Creating a DAEMON */

	// fork a process
	pid = fork(); 

	// re-parenting by terminating the parent process
	// child will become an orphan and be re-parented to 1

	if(pid!=-1 && pid!=0) {
		exit(0);
	}

	getchar();

	// creating a new session & assigning this process
	setsid(); 

	// change the dir to root /
	chdir("/");

	// close all the default file-descriptors
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	// open a log file
	fp = fopen("/daemonlog.txt","w+");
	
	// writing into the log file
	while(1) {

		sleep(1);
		fprintf(fp, "Logging into daemon...n\n");
	        fflush(fp);
	}	



	return 0;

}

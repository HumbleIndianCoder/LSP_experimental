#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

	pid_t pid;

	pid = fork();
	/* returns 0 for child process
	 * return pid of child to parent process
	 * returns -1 if process creation fails
	 */

	if(pid==0 && pid!=-1) {
		printf(" CHILD Process ID = %d ", getpid());
        	printf(" Parent Process ID of child = %d \n", getppid());

	} 

	if(pid!=0 && pid!=-1) {
		printf(" Parent Process ID = %d ", getpid());
        	printf(" Parent Process ID of Parent = %d \n", getppid());

	}

	getchar();


	return 0;
}

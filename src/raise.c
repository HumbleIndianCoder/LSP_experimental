#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>


int main() {

	int pid, status;

	
	kill(getpid(), SIGKILL); // to kill the child
	
	//raise(SIGKILL);

	getchar();	

	return 0;

}

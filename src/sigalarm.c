#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sighandler(int sig) {
	printf(" handler invoked by SIGALRM \n");
}

int main() {

		
	signal(SIGALRM, sighandler);
	printf("Setting up an alarm\n");

	alarm(10);
	printf("Alarm set\n");

	pause(); // blocking call


	return 0;
}

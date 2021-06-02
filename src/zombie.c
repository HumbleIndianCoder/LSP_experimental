#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {

	int pid, status;

	pid = fork();

	if(pid!=-1 && pid ==0) {
		// Child Process
		printf(" The PID  = %d & PPID = %d\n", getpid(), getppid());

	}

	if(pid!=-1 && pid !=0) {
		// Parent Process
                printf(" The PID  = %d & PPID = %d\n", getpid(), getppid());
		//wait(&status);
		//sleep(50);
        }

	getchar();


	return 0;

}

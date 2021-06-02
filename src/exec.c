#include<stdio.h>
#include<unistd.h>

int main() {

	int pid;

	char *argv1[] = {"cat","/usr/include/sysexits.h",NULL};
	char *argv2[] = {"ls","-l",NULL};
	pid = fork();

	if(pid!=-1 && pid==0) {

		//execvp(argv1[0], argv1);
		execvp(argv2[0], argv2);
	
	}




	return 0;
}

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main() {


	int fdwrite;
	char writebuffer[100];

	mkfifo("fifo3", 0664);

	while(1) {

		fdwrite = open("fifo3", O_WRONLY);
		fgets(writebuffer, 100, stdin);
		write(fdwrite, writebuffer, sizeof(writebuffer));

	}


	return 0;
}

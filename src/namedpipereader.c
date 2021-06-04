#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main() {


	int fdread;
	char readbuffer[100];

	mkfifo("fifo3", 0664);

	while(1) {

		fdread = open("fifo3", O_RDONLY);
		
		read(fdread, readbuffer, sizeof(readbuffer));
		printf("%s\n", readbuffer);

	}


	return 0;
}

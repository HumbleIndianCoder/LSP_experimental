#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>


int main() {

	int fdread, fdwrite;
	char buf[100];
	int bytesread;

	fdread = open("source.txt", O_RDONLY);
	if(fdread == -1) {
		printf("\n The open call failed and reason is %d \n", errno);
		return 0;
	}
	
	fdwrite = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
        if(fdwrite == -1) {
                printf("\n The write call failed and reason is %d \n", errno);
                return 0;
        }

	while( (bytesread = read(fdread, &buf, sizeof(buf))) > 0 ) {

		write(fdwrite, &buf, bytesread); // write to dest file
		write(1, &buf, bytesread); // write to console
		perror("write = ");

	}

	close(fdread);
	close(fdwrite);
}



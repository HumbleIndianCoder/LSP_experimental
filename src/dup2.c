#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main() {

	int fd1, fd2;
	char buf[100];

	fd1 = open("source.txt", O_RDONLY);
	fd2 = open("dest.txt", O_WRONLY | O_TRUNC);

	read(fd1, &buf, 100);

	// creates a duplicate descriptor for fd2 --> STD_OUT , so whatever is printed will be written into fd2 file.
	dup2(fd2, STDOUT_FILENO);

	printf("%s", buf);

	return 0;
}

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main() {


	int fd;
	fd = open("input.txt", O_RDONLY);

	printf("The fd value = %d\n", fd);

	getchar();

	close(fd);
}

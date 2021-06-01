#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {

	int fd;
	char buf[100];

	fd = open("input.txt", O_RDWR); // 0

	read(fd, &buf, 100); // 100
	getchar();

	lseek(fd, 10, SEEK_CUR); // 110
	getchar();

	read(fd, &buf, 100); // 210
	getchar();

	lseek(fd, -100, SEEK_CUR); // 110
	getchar();


		
}

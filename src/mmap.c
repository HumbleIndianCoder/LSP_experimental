#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>

int main() {

	int fd;
	void *mptr;

	// open the file to be mapped
	fd = open("source.txt", O_RDONLY);

	getchar();
	// mapping the file to the process addr space
	mptr = mmap(0, 100, PROT_READ, MAP_SHARED, fd, 0); 

	printf("%s\n", (char *)mptr);

	getchar();
	// unmapping
	munmap(mptr, 100);



	return 0;
}

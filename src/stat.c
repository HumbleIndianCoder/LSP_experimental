#include<stdio.h>
#include<sys/stat.h>


int main() {

	struct stat buf;

	stat("open.c", &buf);

	printf("inode = %lu\t user-id = %d\t ; mode = %o\n", buf.st_ino, buf.st_uid, buf.st_mode);


	return 0;

}

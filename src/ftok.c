#include<stdio.h>
#include<sys/ipc.h>


int main() {

	int key1, key2, key3;

	key1 = ftok(".", 10);
	key2 = ftok("open.c", 100);
	key3 = ftok("ftok.c", 100);

	printf(" The keys are key1 = %d ; key2 = %d ; key3 = %d \n", key1, key2, key3);

	return 0;
}

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>


int main() {

	int key, shm_id;
	void *shmptr;

	key = ftok(".", 10);

	// get the shared memory id
	shm_id = shmget(key, 512, 0);

	getchar();
	// attach to the shared memory segment
	shmptr = shmat(shm_id, 0, 0);

	// reading from the shared segment
	printf("%s\n",(char *)shmptr);

	getchar();

	// detach from the shared memory segment
	shmdt(shmptr);

	return 0;
}

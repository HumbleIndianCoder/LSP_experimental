#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>


int main() {

	int key, shm_id;
	void *shmptr;

	key = ftok(".", 10);

	// get the shared memory id
	shm_id = shmget(key, 512, IPC_CREAT | 0644);
	printf(" A shared memory segment is created with id %d \n",shm_id);

	getchar();
	// attach to the shared memory segment
	shmptr = shmat(shm_id, 0, 0);

	// writing to the shared segment
	strcpy((char *)shmptr, "Writing to shared memory segment \0");

	getchar();

	// detach from the shared memory segment
	shmdt(shmptr);

	return 0;
}

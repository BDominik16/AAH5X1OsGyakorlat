
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 123456L



main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;

	key = SHMKEY;
	shmflg = 0;
	if ((shmid=shmget( key, size, shmflg)) < 0) {
	   printf("\n Nincs meg szegmens! Keszitsuk el!");
	   shmflg = 00666 | IPC_CREAT;
	   if ((shmid=shmget( key, size, shmflg)) < 0) {
	      perror("\n Az shmget system-call sikertelen!");
	      exit(-1);
	   }
	} else printf("\n Van mar szegmens!");

	printf("  Az shmid azonositoja %d: \n", shmid);

	exit (0);
}

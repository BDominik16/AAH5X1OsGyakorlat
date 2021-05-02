#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

int semID, nsems, r, semflag;
unsigned nsops;
struct sembuf sembuf, *sop;

int main()
{
	nsems = 1;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ){
        perror("hiba!\n");
        return 0;
    }
	else
        printf("Azonosító: %d\n",semID);

	nsops = 1;
	sembuf.sem_flg = 0666;
	sembuf.sem_op = 1;
	sembuf.sem_num = 0;
	sop = &sembuf;
	r = semop(semID, sop, nsops);
	printf("Visszatérési érték: %d\n",r);

    return 0;

}

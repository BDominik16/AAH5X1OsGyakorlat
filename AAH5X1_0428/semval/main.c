#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

int semID,nsems,r, cmd, semflag;
struct sembuf sembuf, *sop;
union semun arg;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main()
{
	semflag = 00666 | IPC_CREAT;
	nsems = 1;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ) {
        perror("hiba!\n");
        return 0;
    }
	else
        printf("Azonosító: %d\n",semID);
	r = semctl(semID,0, cmd, NULL);
	cmd = GETVAL;
	printf("Kiolvasott értéke: %d\n",r);
    return 0;

}

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semID,nsems,semnum,r, semflag, cmd;
struct sembuf sembuf, *sop;
union semun;

int main()
{
    int arg;
	nsems = 1;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ) {
        perror("hiba!\n");
        return 0;}
	else
        printf("Az azonosító: %d\n",semID);
	printf ("Kérem a semval értéket: ");

	semnum = 0;
	cmd = SETVAL;
	scanf("%d", &arg);
	r = semctl(semID, semnum, cmd, arg);
	printf("\nVisszatérési érték: %d , semval érték: %d\n",r, arg);

    return 0;

}

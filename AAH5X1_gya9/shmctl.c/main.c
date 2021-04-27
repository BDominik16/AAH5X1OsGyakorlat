
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
	int rtn;
	int cmd;
	struct shmid_ds shmid_ds, *buf;
	buf = &shmid_ds;

	key = SHMKEY;
	shmflg = 0;
	if ((shmid=shmget( key, size, shmflg)) < 0) {
	    perror("\n Az shmget system-call sikertelen!");
	    exit(-1);
	}


	do {
	printf("\n Add meg a parancs szamat ");
	printf("\n 0 IPC_STAT (status) ");
	printf("\n 1 IPC_RMID (torles)   >  ");
	scanf("%d",&cmd);
	} while (cmd < 0 && cmd > 1);

	switch (cmd)
	{
	case 0: rtn = shmctl(shmid, IPC_STAT, buf);
		printf("\n  Segm. meret: %d",buf->shm_segsz);
		printf("\n  Utolso shmop-os proc. pid: %d\n ",buf->shm_lpid);
		break;
	case 1: rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("\n Szegmens torolve\n");
	}

	exit(0);

}

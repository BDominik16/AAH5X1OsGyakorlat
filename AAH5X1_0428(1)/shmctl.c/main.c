#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13V

main()
{
  int bolgar;
  key_t key;
  int meret = 512;
  int flg, rtn, sm;
  struct bolgar_ds bolgar_ds, *buf;

  buf = &bolgar_ds;
  key = SHMKEY;
  flg = 0;

  if((bolgar = shmget(key, meret, flg)) < 0)
  {
     perror("\n Sikertelen volt a shmget!");
     exit(-1);
  }

  do {
    printf("\n Valasszon a menubol");
    pritnf("\n 0. status lekerese");
    printf("\n 1. memoria torlese");
    scanf("%d", &sm);
  }while(sm < 0 && sm > 1);

  switch(sm)
  {
    case 0: rtn = shmctl(bolgar, IPC_STAT, buf);
        printf("\n meret: %d", buf->shm_segsz);
        printf("\n pid: %d", buf->shm_lpid);
        break;
    case 1: rtn = shmctl(bolgar, IPC_RMID, NULL);
        printf("\n szegmens megszüntetve");
  }

  exit(0);
}

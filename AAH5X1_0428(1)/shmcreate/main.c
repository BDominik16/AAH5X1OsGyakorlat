shmcreate.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13V

int main()
{
  int bolgar;
  key_t key;
  int meret = 512;
  int flg;

  key = SHMKEY;
  flg = 0;
  if((bolgar= shmget(key, meret, flg)) < 0)
  {

     flg = 00666 | IPC_CREAT;
     if((bolgar = shmget(key, meret, flg)) < 0)
     {
    perror("\n Sikertelen volt a shmget!");
    exit(-1);
     }
  }
  //else = van már ilyen szegmens

  printf("Az azonosító : %d", shmid);
  return 0;
}




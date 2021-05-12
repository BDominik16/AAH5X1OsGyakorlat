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

  struct str {
     int lng;
     char text[512-sizeof(int)];
  } *segment;

  key = SHMKEY;
  flg = 0;

  if((bolgar = shmget(key, meret, flg)) < 0)
  {
     perror("\n Sikertelen volt a shmget!");
     exit(-1);
  }

  flg = 00666 | SHM_RND;
  segment = (struct str *)shmat(bolgar, NULL, flg);

  if(segment == (void *) - 1)
  {
     perror("\n Sikertelen csatlakozas");
     exit(-1);
  }

  if(strlen(segment->text) > 0)
  {
     printf("\n A regi szoveg : %s", segment->text);
  }

   printf("\n Adja meg az uj szoveget : ");
   gets(segment->text);
   printf("\n\n Az uj szoveg : %s \n", segment->text);

   shmdt(segment);
   exit(0);
}

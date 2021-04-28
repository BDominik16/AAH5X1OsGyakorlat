#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int gyerek;

        if((gyerek=fork())==0) //itt kinyerjük a gyerek pidjét mert a fork azonosítója  a pidje
        {
        execl("./Proc2","Proc2",(char *)NULL); //az execl
        }
        printf("Szülő vagyok, pidem: %d\n", getpid());
        printf("Gyerekem pidje: %d\n",gyerek);//pid kiírás
        waitpid(gyerek, NULL, 0);//bevárja a gyereket

return 0;
}
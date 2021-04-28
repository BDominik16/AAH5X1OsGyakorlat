#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        printf("Gyerek vagyok, pidem: %d\n", getpid());
        printf("Szülöm pidje: %d\n",getppid());	
	return 0;
}
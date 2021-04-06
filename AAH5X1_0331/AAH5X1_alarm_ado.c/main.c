#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

main(int argc, char **argv)
{
	int pid;

	if (argc < 1)
	{
		perror(" Nincs kinek");
		exit(1);
	}

	pid = atoi(argv[1]);

	kill(pid, SIGALRM);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int child;

    mkfifo("kprlnb",S_IRUSR | S_IWUSR);

    child = fork();

    if(child>0)
    {
        char s[1024];
        int fd;

        fd = open("kprlnb",O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s",s);

        close(fd);
        unlink("kprlnb");
    }else if("kprlnb");
    int fd;
    return 0;
}

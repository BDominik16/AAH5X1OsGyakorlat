#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);
    printf("A pidem: %d", getpid());
    sleep(3);
    sem_post(&mutex);
}


int main()
{
    sem_init(&mutex, 0, 2);
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,thread,NULL);
    pthread_create(&t2,NULL,thread,NULL);
	pthread_create(&t3,NULL,thread,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
	pthread_join(t3,NULL);
    sem_destroy(&mutex);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleSignal(int signum);

int main(void) {

    void (*sigHandlerInterrupt)(int);
    void (*sigHandlerQuit)(int);
    void (*sigHandlerReturn)(int);
    sigHandlerInterrupt = sigHandlerQuit = handleSignal;
    sigHandlerReturn = signal(SIGINT, sigHandlerInterrupt);
    if (sigHandlerReturn == SIG_ERR) {
        perror ("signal error: ");
        return 1;
    }
    sigHandlerReturn = signal(SIGQUIT, sigHandlerQuit);

    if(sigHandlerReturn == SIG_ERR){
        perror("signal error: ");
        return 1;
    }

    while(1){
            printf("\n A program leallitasahoz a kovetkezoket vegezze el: \n");
            printf("1. Nyisson meg egy masik terminalt. \n");
            printf("2. Adja ki parancsot: kill %d vagy kiadja CTRL+C 2-szer\n",getpid());

    }

    return 0;
}

void handleSignals(int signum){
    switch(signum){
    case SIGINT:
        printf("\n Nyomja meg a CTRL+ C billentyukombinaciot\n");
        printf("Most visszaallitja a SIGINT jelet az alapertelmezett muveletre\n");
        signal(SIGINT, SIG_DFL);
        break;
    case SIGQUIT:
        printf("\n Nyomja meg a CTRL+\n");
        break;
    default:
        printf("\nFogadott jel szama: %d\n",signum);
        break;
    }
    return;

}



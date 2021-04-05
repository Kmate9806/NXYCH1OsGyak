#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleSignals(int signum);

int main() {
    void (*sigInterruptHandler)(int);
    void (*sigQuitHandler)(int);
    void (*sigReturnHandler)(int);
    sigInterruptHandler = sigQuitHandler = handleSignals;
    sigReturnHandler = signal(SIGINT, sigInterruptHandler);
    if (sigReturnHandler == SIG_ERR){
        perror("Signal error! Program exiting...");
        return 1;
    }
    sigReturnHandler = signal(SIGQUIT, sigQuitHandler);

    if (sigReturnHandler == SIG_ERR){
        perror("Jel hiba! kilep a program...");
        return 1;
    }
    while(1){
        printf("\n ha kiakar lepni, kovesse az utasitasokat:\n");
        printf("1. uj terminal nyitasa.\n");
        printf("2. Ezt a parancsot adja ki: kill %d vagy issue CTRL + C 2 times.", getpid());
        sleep(10);
    }
    return 0;
}

void handleSignals(int signum){
    switch(signum){
        case SIGINT:
            printf("\n  Nyomja meg a  CTRL + C");
            printf("Most visszaallitja a SIGINT jelet az alap eljarasra");
            signal(SIGINT, SIG_DEL);
            break;
        case SIGQUIT:
            printf("\n  Nyomja meg a CTRL+\n");
            break;
        default:
            printf("\n  A kapott jelek szama: %d\n", signum);
            break;
    }
    return;
}

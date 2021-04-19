#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void TerminationHandler(int sig);

int main(void)
{
    if (signal(SIGTERM, TerminationHandler) == SIG_ERR)
    {
        printf("Nem sikerult a handlert allitani a \"SIGTERM\" jelre!\n");
        return 0;
    }

    while(1)
    {
        printf("Varakozom...\n");
        sleep(3);
    }

    return 0;
}

void TerminationHandler(int sig)
{
    signal(sig, SIG_IGN);
    printf("SIGTERM signal: %d\n", sig);
}

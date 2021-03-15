#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    pid_t  valami;
    int status;

    if((valami=fork())<0) perror("hiba");

    else if(valami==0) exit(9);

    if (wait(&status) != valami) perror("idotullepes");

    if (WIFEXITED(status)) printf("Szabalyos befejezes %d\n", WEXITSTATUS(status));

    if ((valami = fork())<0) perror("hiba");
    else if(valami==0) abort();
    if(wait(&status)) printf("Nem jo befejezes %d\n",WTERMSIG(status));

    if((valami==fork()) <0) perror("hiba");
    else if(valami==0) {int a;int b=0; a=10/b;}
    if(wait(&status) !=valami) perror("idotullepes");
    if(WIFSIGNALED(status)) printf("nem jo befejezes %d\n",WTERMSIG(status));

    exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t valami;
    if ( ( valami=fork()) < 0) perror("hiba");
    else if (valami == 0) execlp("date", "child",NULL);
    if (waitpid(valami,NULL,0) < 0 ) perror("megy");
   exit(0);
}

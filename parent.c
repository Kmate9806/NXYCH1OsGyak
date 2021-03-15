
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
pid_t asd = fork();
if(asd==0) execl("./child.out", "child",NULL);
else perror("hiba");
return 0;
}

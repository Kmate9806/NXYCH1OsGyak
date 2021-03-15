#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int system(const char *command);


int main()
{
    char gets(char *command);
    char szov[64];
    gets(szov);

    char szov2[32];
    strcpy(szov2,szov);
    system(szov2);


    return 0;
}

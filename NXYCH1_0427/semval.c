#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//kulcs definialasa:
#define SEMKEY NX12YCH

    int semid,numofsems,rtn;
    int semflg;
    union semun{int val;
    struct semid_ds *buf;
	unsigned short *array;}arg;
    union semun arg;
    int cmd;

main()
{


    numofsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, numofsems, semflg);
    if (semid < 0 ) {perror(" hibas a semaforszam"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n");

    cmd = GETVAL;
    rtn = semctl(semid,0, cmd, NULL);

    printf("\n semval: %d ",rtn);
    printf("\n");

}

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//kulcs definialasa:
#define SEMKEY NX12YCH


    int semid,numofsems,rtn;
    int semflg;
    struct sembuf sembuf, *sop;
    union semunio{int val;
    struct semid_ds *buf;
	unsigned short *array;}arg;
    int cmd;

main()
{


    numsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, numofsems, semflg);
    if (semid < 0 ) {perror(" hibas a semaforszam"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n");

    //megszuntetes
    cmd = IPC_RMID;
    rtn = semctl(semid,0, cmd, arg);

    printf("\n kill rtn: %d ",rtn);
    printf("Megszunt.\n");

}

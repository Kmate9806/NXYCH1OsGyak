#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//kulcs definialasa:
#define SEMKEY NX12YCH
    int semid,	 semaphor set azonosito
        numofsems,	 semaphorok szama a keszletben
        semnum,	 semapho szam a set-en belul
        rtn;	 visszateresi ertek

    int semflg;	// flag
    struct sembuf sembuf, *sop;
    union semunio{int val;
    struct semid_ds *buf;
	unsigned short *array;}arg;
    int cmd;	// semctl-nek szolo parancs

int main()
{


    nsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, numofsems, semflg);
    if (semid < 0 ) {perror(" hibas a semaforszam"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n kerem a semval erteket ");

    semnum = 0;

    cmd = SETVAL;
    scanf("%d",&arg.val);
    rtn = semctl(semid,semnum, cmd, arg);


    printf("\n set  rtn: %d ,semval: %d ",rtn,arg.val);
    printf("\n");

    return 0;
}

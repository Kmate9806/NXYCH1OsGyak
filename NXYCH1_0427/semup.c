#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//kulcs definialasa:
#define SEMKEY NX12YCH

    int semid,numofsems,rtn;
    unsigned nsops;	// semop-ban ezzel adjuk meg, hany semaphore strukturaval foglakozzon

    int semflg;
    struct sembuf sembuf, *sop;


main()
{


    nsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, numofsems, semflg);
    if (semid < 0 ) {perror(" hibas a semaforszam"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n");

    nsops = 1;
    sembuf.sem_num = 0;
    sembuf.sem_op = 1;
    sembuf.sem_flg = 0666;	// Flag beallitas
    sop = &sembuf;
    rtn = semop(semid, sop, nsops);

    printf("\n up rtn: %d ",rtn);
    printf("\n");

}

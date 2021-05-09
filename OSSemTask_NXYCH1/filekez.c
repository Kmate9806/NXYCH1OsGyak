#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int fdf;


void handler(void) {    // letrehozok egy handler metodust hogy lezarjam a fifot 
close(fdf);

	unlink("myfifo");


}
int main()
{
	// deklaralom a valtozoimat:
	int fd, ret,retfifo;
	
	//letrehozok egy char buf tombot a szokezelesre.
	char buf[64];

	buf[0]=0;


        retfifo=mkfifo("myfifo",00666);	// letrehozom a fifo-t a filerendszeren a retfifo el hivatkozom majd ra.
	if (ret == -1) {
	    perror("Nem jon letre a fifo");
	    exit(-1);  // elso kilepesi pont ha hiba van a letrehozasnal
	}

	fdf=open("myfifo",O_RDWR);	// megnyitom a fifot amit az iment hoztam letre
	if (fdf == -1) {
	    perror("Megnyitasi hiba a fifonal");
	    exit(-1);   //masodik kilepesi pont ha hibas a megnyitas
	}

	int c = 0 ;    // ciklusvaltozo
	int i = 0 ;    // a sorszamozashoz hasznalt valtozo
	while(c==0){
	retfifo=read(fdf,buf,64); // kiolvasom a csobol amit beleirtam, megnezem mennyit sikerult kiolvasni
	fd=open("tarol.txt",O_RDWR);  // a tarol.txt mappaban fogom tarolni a csobol erkezo szavakat
	if (fd == -1) {
	    perror("megnyitasi hiba");
	    exit(-1); // a harmadik kilepesi pont ha hiba lenne megnyitasnal
	}
	
	
	ret=write(fd,buf,strlen(buf));
	ret=write(fd,&i,sizeof(int));
	i++;
	
	scanf("%d",&c);
	}
	
	
	signal(SIGTERM, (void (*)()) handler);	//  SIGTERM signalt hasznalok. lekapcsolom a csövet.
}

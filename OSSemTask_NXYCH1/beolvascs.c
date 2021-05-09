#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	//letrehozom a valtozoimat illetve a csovet es a char buf tombot amivel a csobe a szavakat teszem
	int fd, ret;
	char buf[64];

	buf[0]=0;


        

	fd=open("myfifo",O_RDWR);	// megnyitom a myfifo-t amit letrehoztam
	if (fd == -1) {
	    perror("megnyitasi hiba");
	    exit(-1); //elso kilepesi pont amennyiben hiba lenne a megnyitasnal 
	}
	
	int c=0;  // letrehozok egy ciklusvaltozot
	
	printf("Amikor a c erteke 0 beolvas , ha kiakarok lepni akkor 0 tol eltero erteket adok meg. \n");
	printf("Irj be szavakat amiket tarolni szeretnel \n");
	while(c==0){  // ameg 0 lesz a c beolvas , amint mas erteket kap kilep 
	
	printf("szo: ");
	
	scanf("%s",buf);   //beolvasom a szavakat 
	
	write(fd,buf,strlen(buf)); // beleirom a csobe a szavakat amiket beolvasok
	
	
	scanf("%d",&c);   // beolvasom a c erteket hogy toltom e tovabb a csovet vagy kilepek belole.
	}

	close(fd);    // lezarom a csovet

	
}

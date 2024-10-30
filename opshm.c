#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSZ 4096
int main(int argc, char *argv[]) { 
int shmid;  /* ID ñåãìåíòà */
char *shmbuf; /* Àäðåñ â àäðåñíîì ïðîñòðàíñòâå ïðîöåññà */ 
int fd; /* Ôàè?ëîâûè? äåñêðèïòîð */
int i; /* Ñ÷åò÷èê */ 
if(argc != 2) { /* id ñåãìåíòà äîëæíî ïåðåäàâàòüñÿ â êîìàíäíîè? ñòðîêå */ 
puts(“USAGE: opshm <identifier>”);
exit (EXIT_FAILURE); 
}
shmid = atoi(argv[1]);
if((shmbuf = shmat(shmid, 0, 0)) < (char *)0) { /* Ïðèñîåäèíÿåì ñåãìåíò */ 
    perror("shmat"); 
    exit(EXIT_FAILURE); 
} 
if((shmbuf = malloc(sizeof(char) * BUFSZ)) == NULL) { /* Ðåçåðâèðóåì ïàìÿòü äëÿ shmbuf */ 
   perror("malloc"); 
   exit(EXIT_FAILURE); 
} 
for(i = 0; i < BUFSZ; ++i) shmbuf[i] = i % 127; 
fd = open("opshm.out", O_CREAT ¦ O_WRONLY, 0600); 
fwrite(fd, shmbuf, BUFSZ);
exit(EXIT_SUCCESS); 
} 

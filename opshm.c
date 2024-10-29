#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSZ 4096
int main(int argc, char *argv[]) { 
int shmid;  /* ID сегмента */
char *shmbuf; /* јдрес в адресном пространстве процесса */ 
int fd; /* ‘аи?ловыи? дескриптор */
int i; /* —четчик */ 
if(argc != 2) { /* id сегмента должно передаватьс€ в команднои? строке */ 
puts(УUSAGE: opshm <identifier>Ф);
exit (EXIT_FAILURE); 
}
shmid = atoi(argv[1]);
if((shmbuf = shmat(shmid, 0, 0)) < (char *)0) { /* ѕрисоедин€ем сегмент */ 
    perror("shmat"); 
    exit(EXIT_FAILURE); 
} 
if((shmbuf = malloc(sizeof(char) * BUFSZ)) == NULL) { /* –езервируем пам€ть дл€ shmbuf */ 
   perror("malloc"); 
   exit(EXIT_FAILURE); 
} 
for(i = 0; i < BUFSZ; ++i) shmbuf[i] = i % 127; 
fd = open("opshm.out", O_CREAT ¶ O_WRONLY, 0600); 
write(fd, shmbuf, BUFSZ);
exit(EXIT_SUCCESS); 
} 

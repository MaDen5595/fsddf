#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSZ 512 
struct msg { /* ��������� ��������� */ 
   long msg_type; 
   char msg_text[BUFSZ]; 
}; 
int main(int argc, char *argv[]) { 
int qid; /* ������������� ������� */
int len; /* ������ ��������� */
struct msg pmsg; /* ��������� �� ��������� */
if(argc != 2) {  /* ID ������ ���� ������� � ���������? ������ */ 
   puts("USAGE: qsnd <queue ID>"); 
   exit(EXIT_FAILURE); 
} 
qid = atoi(argv[1]);
/* �������� � ���������� ��������� �� ������� */ 
len = msgrcv(qid, &pmsg, BUFSZ, 0, 0); 
if(len > 0) { 
    printf("reading queue id: %05d\n", qid); 
    printf("\tmessage type: %05d\n", (&pmsg) ->msg_type); 
    printf("\tmessage text: %s\n", (&pmsg) ->msg_text); 
} else {
    perror("msgrcv"); 
    exit(EXIT_FAILURE); 
} 
    exit(EXIT_SUCCESS); 
}

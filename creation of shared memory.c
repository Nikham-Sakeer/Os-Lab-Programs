#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/shm.h>

#include<string.h>

void main() {
  char buff[100];

 char ans;

 int shmid, ch, key;

 void *shared_memory;

 do {

 printf("\n\tMENU\n-------------------\n1 Write to memory\n2 Read to memory\n\nYour Choice : ");

 scanf("%d",&ch);

 switch(ch) {

 case 1 :

 printf("\nEnter unique key for the memory space : ");

 scanf("%d",&key);

 shmid = shmget((key_t)key,1024,0666|IPC_CREAT);

 printf("\nKey of shared memory : %d\n",shmid);

 shared_memory = shmat(shmid,NULL,0);

 printf("Process attached at %p\n",shared_memory);

 printf("\nEnter some data to write to the shared memory : ");

 scanf("%s",buff);

 strcpy(shared_memory,buff);

 printf("\nYou wrote : %s\n",(char*)shared_memory);

 break;

 case 2 :

 printf("\nEnter key of the memory space : ");

 scanf("%d",&key);

 shmid = shmget((key_t)key,1024,0666);

 printf("\nKey of shared memory is %d\n",shmid);

 shared_memory = shmat(shmid,NULL,0);

 printf("Process attached at %p\n",shared_memory);

 printf("\nData read from shared memory is : %s\n",(char*)shared_memory);

 break;
     default :

 printf("\nEnter a valid option");

 break;

 }

 printf("\nWould you like to continue(y/n)? ");

 scanf(" %c",&ans);

 }

 while(ans=='y');

 shmdt(shared_memory);

 shmctl(shmid,IPC_RMID,NULL);

}

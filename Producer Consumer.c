#include <stdio.h>

#include <stdlib.h>
#include <pthread.h>

#include <semaphore.h>

#define MAX 3

#define BufferSize 3

sem_t empty;

sem_t full;

int in = 0;

int out = 0;

int i=0,j;

int buffer[BufferSize];

void *producer() 

{

int item = rand();

sem_wait(&empty);

buffer[in] = item;

printf("Producer inserted item %d at %d\n",buffer[in],in);

in = (in+1)%BufferSize;

i++;

sem_post(&full);

}

void *consumer()

{

sem_wait(&full);

int item = buffer[out];

printf("Consumer removed Item %d from %d\n",item,out);

i--;

out = (out+1)%BufferSize;
  sem_post(&empty);

}

void main()

{

pthread_t pro,cons; 

sem_init(&empty,0,BufferSize);

sem_init(&full,0,0);

int a[100], ch;

while(1) {

printf("\n\t\tMENU");

printf("\n--------------------------------");

printf("\n1. Producer\n2. Consumer\n3. Display\n4. Exit");

printf("\n\nEnter your choice : ");

scanf("%d",&ch);

printf("\n");

switch(ch) {

case 1 : if(i == BufferSize) {

printf("Buffer is FULL !!!");

break;

}

pthread_create(&pro, NULL, (void *)producer,(void *)&a[in]);

pthread_join(pro, NULL);

break;

case 2 : if(i == 0) {

printf("Buffer is EMPTY !!!\n");

break;

}

pthread_create(&cons, NULL, (void *)consumer,(void *)&a[in]);
    pthread_join(cons, NULL);

break;

case 3 : if(i == 0) {

printf("Buffer is EMPTY !!!\n");

break;

}

printf("The Contents in buffer are : \n");

for(j=0;j<i;j++)

printf("\t%d :\t%d\n",j,buffer[j]);

break;

case 4 : exit(0);

break;

default : printf("Invalid choice !!!");

}

}

sem_destroy(&empty);

sem_destroy(&full);

}

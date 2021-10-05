#include <stdio.h>

int blocknum, filenum, files[100], blocks[100], done[100];

void worst()

{

int max, maxind;

printf("\n File Size\t|\tFile No.\t|\tBlock No.\t|\tBlock Size\t|\tFragment");

for (int i = 0; i < filenum; i++)

{

 max = blocks[0];

 maxind = 0;

 for (int j = 1; j < blocknum; j++)

 {

 if (blocks[j] > max && done[j] != 1)

 {

 max = blocks[j];

 maxind = j;

 }

 }

 done[maxind] = 1;

 if (blocks[maxind] >= files[i])

 printf("\n %d\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\t%d", files[i], i + 1, maxind + 1, 

blocks[maxind], blocks[maxind] - files[i]);

}

}

void best()

{

int min, minind;

printf("\n File Size\t|\tFile No.\t|\tBlock No.\t|\tBlock Size\t|\tFragment");

for (int i = 0; i < filenum; i++)

{

 min = 1000;

 for (int j = 0; j < blocknum; j++)

 {

 if (blocks[j] >= files[i] && done[j] != 1)
   {

 if (min > blocks[j])

 {

 minind = j;

 min = blocks[j];

 }

 }

 }

 done[minind] = 1;

 printf("\n %d\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\t%d", files[i], i + 1, minind + 1, 

blocks[minind], blocks[minind] - files[i]);

}

}

void first()

{

printf("\n File Size\t|\tFile No.\t|\tBlock No.\t|\tBlock Size\t|\tFragment");

for (int i = 0; i < filenum; i++)

{

 for (int j = 0; j < blocknum; j++)

 {

 if (blocks[j] >= files[i] && done[j] != 1)

 {

 done[j] = 1;

 printf("\n %d\t\t|\t%d\t\t|\t%d\t\t|\t%d\t\t|\t%d", files[i], i + 1, j + 1, blocks[j], 

blocks[j] - files[i]);

 break;

 }

 }
  
  }

}

int main()

{

char c;

int o;

do

{

 printf("\nEnter the number of blocks : ");

 scanf("%d", &blocknum);

 printf("\nEnter the number of files : ");

 scanf("%d", &filenum);

 for (int i = 0; i < filenum; i++)

 done[i] = 0;

 printf("\n\nEnter the size of each block : \n");

 for (int i = 0; i < blocknum; i++)

 {

 printf("Block %d : ", i + 1);

 scanf("%d", &blocks[i]);

 }

 printf("\nEnter the size of each file : \n");

 for (int i = 0; i < filenum; i++)

 {

 printf("File %d : ", i + 1);

 scanf("%d", &files[i]);

 }

 printf("\nChoose your option :\n 1. Worst Fit\n 2. Best Fit\n 3. First Fit\nYour choice : ");

 scanf("%d", &o);

 switch (o)
   {

 case 1:

 worst();

 break;

 case 2:

 best();

 break;

 case 3:

 first();

 break;

 default:

 printf("\nEnter a valid option.");

 break;

 }

 printf("\n\nWould you like to continue? (y/n) : ");

 scanf("%s", &c);

} while (c == 'y');

return 0;

}

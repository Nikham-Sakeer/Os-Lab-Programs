#include <stdio.h>

#include <stdlib.h>

int elements[100], size, head, track;

void sort()

{

int temp;

for (int i = 0; i < size - 1; i++)

{

 for (int j = 0; j < size - i - 1; j++)

 {

 if (elements[j] > elements[j + 1])

 {

 temp = elements[j];

 elements[j] = elements[j + 1];

 elements[j + 1] = temp;

 }

 }

}

}
void fcfs()

{

int seek;

printf("\nThe seek sequence is : ");

for (int i = 0; i < size; i++)

 printf("%d\t", elements[i]);

seek = abs(elements[0] - head);

for (int i = 1; i < size; i++)

 seek += abs(elements[i] - elements[i - 1]);

printf("\nTotal seek time : %d", seek);

}

void scan()

{

int seek, pos = 0, flag, done = 0;

while (done != 1)

{

 if (elements[pos] >= head)

 {

 flag = pos;

 printf("\nThe seek sequence is : ");

 for (int i = pos; i < size; i++)

 printf("%d\t", elements[i]);

 seek = ((track - 1) - head);

 for (int i = (flag - 1); i >= 0; i--)

 printf("%d\t", elements[i]);
   seek += ((track - 1) - elements[0]);

 printf("\nTotal seek time : %d", seek);

 done = 1;

 }

 else

 pos++;

}

}

void cscan()

{

int seek, pos = 0, flag, done = 0;

while (done != 1)

{

 if (elements[pos] >= head)

 {

 flag = pos;

 printf("\nThe seek sequence is : ");

 for (int i = pos; i < size; i++)

 printf("%d\t", elements[i]);

 seek = ((track - 1) - head);

 seek += ((track - 1) - 0);

 for (int i = 0; i <= flag - 1; i++)

 printf("%d\t", elements[i]);

 seek += (elements[flag - 1] - 0);
   printf("\nTotal seek time : %d", seek);

 done = 1;

 }

 else

 pos++;

}

}

int main()

{

char c;

int o;

do

{

 printf("\nEnter the number of tracks : ");

 scanf("%d", &track);

 printf("\nEnter the number of locations on disk : ");

 scanf("%d", &size);

 printf("\nEnter the position of head : ");

 scanf("%d", &head);

 printf("\nEnter the requests to be addressed :\n");

 for (int i = 0; i < size; i++)

 scanf("%d", &elements[i]);

 printf("\nChoose your option :\n 1. FCFS\n 2. SCAN\n 3. C-SCAN\nYour choice : ");

 scanf("%d", &o);

 switch (o)

 {

 case 1:
     fcfs();

 break;

 case 2:

 sort();

 scan();

 break;

 case 3:

 sort();

 cscan();

 break;

 default:

 printf("\nEnter a valid option.");

 break;

 }

 printf("\n\nWould you like to continue? (y/n) : ");

 scanf("%s", &c);

} while (c == 'y');

return 0;

}//end

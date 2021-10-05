#include <stdio.h>

int size, elements[100], frame, page[100], usage[100], time[100];

void fifo()

{

int count = 0, avail;

printf("\n Page Reference\t|\tPage frames");

for (int i = 0; i < size; i++)

{

 printf("\n\t%d\t|\t", elements[i]);

 avail = 0;

 for (int j = 0; j < frame; j++)

 if (page[j] == elements[i])

 avail = 1;

 if (avail == 0)

 {

 page[count] = elements[i];

 if (count < frame - 1)

 count++;

 else

 count = 0;

 for (int j = 0; j < frame; j++)

printf("%d\t", page[j]);

 printf("Miss");

 }

 else

 {

 for (int j = 0; j < frame; j++)

 printf("%d\t", page[j]);

 printf("Hit");

 }

}

}

void lru()

{

int count = 0, avail, max, maxind, timer = 0;

printf("\n Page Reference\t|\tPage frames");

for (int i = 0; i < size; i++)

{

 printf("\n\t%d\t|\t", elements[i]);

 avail = -1;

 timer++;

 for (int j = 0; j < frame; j++)

 if (page[j] == elements[i])

 avail = j;

 if (avail == -1)

 {

 max = timer - usage[0];

 maxind = 0;

 for (int j = 1; j < frame; j++)
 {

 if (timer - usage[j] > max)

 {

 max = timer - usage[j];

 maxind = j;

 }

 }

 if (page[count] == 0 && count < frame)

 {

 page[count] = elements[i];

 usage[count] = timer;

 count++;

 }

 else

 {

 page[maxind] = elements[i];

 usage[maxind] = timer;

 }

 for (int j = 0; j < frame; j++)

 printf("%d\t", page[j]);

 printf("Miss");

 }

 else

 {

 usage[avail] = timer;

 for (int j = 0; j < frame; j++)

 printf("%d\t", page[j]);

 printf("Hit");

 }
 }
 

}

void lfu()

{

int count = 0, avail, max, maxind, timer = 0, temp;

printf("\n Page Reference\t|\tPage frames");

for (int i = 0; i < size; i++)

{

 printf("\n\t%d\t|\t", elements[i]);

 avail = -1;

 timer++;

 for (int j = 0; j < frame; j++)

 if (page[j] == elements[i])

 avail = j;

 if (avail == -1)

 {

 max = usage[0];

 maxind = 0;

 temp = time[0];

 for (int j = 1; j < frame; j++)

 {

 if (max == usage[j])

 {

 if (temp > time[j])

 {

 max = usage[j];

 maxind = j;

 temp = time[j];
 }

 }

 else if (max > usage[j])

 {

 max = usage[j];

 maxind = j;

 temp = time[j];

 }

 }

 if (page[count] == 0 && count < frame)

 {

 page[count] = elements[i];

 usage[count] = 1;

 time[count] = timer;

 count++;

 }

 else

 {

 page[maxind] = elements[i];

 usage[maxind] = 1;

 time[maxind] = timer;

 }

 for (int j = 0; j < frame; j++)

 printf("%d\t", page[j]);

 printf("Miss");

 }

 else

 {

 usage[avail]++;
 for (int j = 0; j < frame; j++)

 printf("%d\t", page[j]);

 printf("Hit");

 }

}

}

int main()

{

char c;

int o;

do

{

 printf("\nEnter the number of frames : ");

 scanf("%d", &frame);

 printf("\nEnter the number of pages : ");

 scanf("%d", &size);

 for (int i = 0; i < frame; i++)

 {

 usage[i] = 0;

 page[i] = -1;

 time[i] = 0;

 }

 printf("\nEnter the page references :\n");

 for (int i = 0; i < size; i++)

 scanf("%d", &elements[i]);

 printf("\nChoose your option :\n 1. FIFO\n 2. LRU\n 3. LFU\nYour choice : ");

 scanf("%d", &o);
 switch (o)

 {

 case 1:

 fifo();

 break;

 case 2:

 lru();

 break;

 case 3:

 lfu();

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

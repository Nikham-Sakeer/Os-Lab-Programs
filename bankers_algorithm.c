#include <stdio.h>

#include <conio.h>

int main()

{

 int max[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];

 int n, m, i, j,k,flag,process, count;

 count = 0;

 printf("\n\t...Banker's Algorithm...\n");

 printf("\nEnter the no of processes : ");

 scanf("%d", &n);

for(i = 0; i< n; i++)

 completed[i] = 0;

 printf("\nEnter the no of resources : ");

 scanf("%d", &m);

 printf("\n\nEnter the allocation for each process : ");

 for(i = 0; i < n; i++)

 {

 printf("\nFor process %d : ",i + 1);

 for(j = 0; j < m; j++)

 scanf("%d", &alloc[i][j]);

 }

 printf("\n\nEnter the Max Matrix for each process : ");

 for(i = 0; i < n; i++)

 {

 printf("\nFor process %d : ", i + 1);

 for(j = 0; j < m; j++)

 scanf("%d", &max[i][j]);

 }

 printf("\n\nEnter the Available Resources : ");

 for(i = 0; i < m; i++)

 scanf("%d", &avail[i]);

 int f[n];

 for (k = 0; k < n; k++) {

 f[k] = 0;
   }

 int need[n][m];

 for (i = 0; i < n; i++) {

 for (j = 0; j < m; j++)

 need[i][j] = max[i][j] - alloc[i][j];

 }

 printf("\n Max matrix:\tAllocation matrix:\n");

 for(i = 0; i < n; i++)

 {

 for( j = 0; j < m; j++)

 printf("%d ", max[i][j]);

 printf("\t\t");

 for( j = 0; j < m; j++)

 printf("%d ", alloc[i][j]);

 printf("\n");

 }

 printf("\n \t...Need Matrix...\n\n");

 for(i = 0; i < n; i++) {

 printf("Need[P%d] \t",i+1);

 for(j = 0; j < m; j++) {

 printf("%d ",need[i][j] );

 }

 printf("\n");

 }

 int y = 0;

 for (k = 0; k < n; k++) {

 for (i = 0; i < n; i++) {

 if (f[i] == 0) {
   int flag = 0;

 for (j = 0; j < m; j++) {

 if (need[i][j] > avail[j]) {

 flag = 1;

 break;

 }

 }

 if (flag == 0) {

 safeSequence[count++] = i+1;

 for (y = 0; y < m; y++)

 avail[y] += alloc[i][y];

 f[i] = 1;

 }

 }

 }

 }

 printf("\n\nFollowing is the SAFE Sequence\n");

 for (i = 0; i < n-1 ; i++)

 printf(" P%d ->", safeSequence[i]);

 printf("P%d", safeSequence[n-1]);

 return (0);

}

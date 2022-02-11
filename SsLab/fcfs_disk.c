#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,seek=0,initial,size;
    printf("Enter the number of Requests: \n");
    scanf("%d",&n);
    printf("Enter the Requests sequence to be addressed: \n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter the initial position of the head: \n");
    scanf("%d",&initial);
    
    for(i=0;i<n;i++)
    {
        seek+=abs(RQ[i]-initial);
        initial=RQ[i];
    }
    
    printf("Total seek time is %d",seek);
    return 0;
    
}

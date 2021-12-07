#include<stdio.h> 
#include<stdlib.h> 
struct process 
{ 
    int no; 
    int bt; 
    int p; 
    int wt; 
    int tat; 
} p[10]; 

void priority(int n) 
{ 
    struct process temp; 
    int i,j; 
    for(i=0;i<n-1;i++) 
    { 
        for(j=0;j<n-i-1;j++) 
        { 
            if(p[j].p>p[j+1].p) 
            { 
                temp = p[j]; 
                p[j] = p[j+1]; 
                p[j+1] = temp;
            } 
        } 
    } 
} 

void tat(int n) 
{ 
    p[0].tat = p[0].bt; 
    for(int i=1;i<n;i++) 
        p[i].tat = p[i-1].tat + p[i].bt; 
}    

void wt(int n) 
{ 
    for(int i=0;i<n;i++) 
        p[i].wt = p[i].tat - p[i].bt; 
} 

void main() 
{ 
    int n; 
    printf("\nEnter the number of processes to simulate : "); 
    scanf("%d",&n); 
    printf("\nEnter the burst time and priority of processes :\n"); 
    for(int i=0;i<n;i++) 
    { 
        printf("\nProcess P[%d]",i+1); 
        p[i].no = i+1; 
        printf("\nBurst time : "); 
        scanf("%d",&p[i].bt); 
        printf("Priority : "); 
        scanf("%d",&p[i].p); 
        printf("\n"); 
    } 
    priority(n); 
    tat(n); 
    wt(n); 
    printf("\nProcess\t|\tBurst time\t|\tPriority\t|\tWaiting time\t|\tTurn around time\t|\n"); 
    for(int i=0;i<n;i++) 
    { 
        printf("P[%d]\t|",p[i].no); 
        printf("\t%d\t\t|",p[i].bt); 
        printf("\t%d\t\t|",p[i].p); 
        printf("\t%d\t\t|",p[i].wt); 
        printf("\t%d\t\t\t|",p[i].tat); 
        printf("\n"); 
    }

} 

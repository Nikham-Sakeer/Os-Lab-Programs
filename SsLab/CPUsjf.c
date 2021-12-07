#include<stdio.h> 
#include<stdlib.h> 

struct process 
{ 
    int no; 
    int bt;
    int at; 
    int ct; 
    int wt; 
    int tat; 
}p[10]; 

void sortarrival(int n) 
{ 
    struct process temp; 
    int j; 
    for(int i=0;i<n-1;i++) 
    { 
        for(j=0;j<n-i-1;j++) 
        { 
            if(p[j].at>p[j+1].at) 
            { 
                temp = p[j]; 
                p[j] = p[j+1]; 
                p[j+1] = temp; 
            } 
        } 
    } 
} 

void sjf(int n) 
{ 
    struct process temp; 
    int i,ready,flag=0; 
    p[0].ct = p[0].at + p[0].bt; 
    ready = p[0].ct; 
    for(int i=1;i<n;i++) 
    { 
        if(p[i].at <= ready) 
        { 
            for(int j=i+1;j<n;j++) 
            { 
                if(p[j].at <= ready && p[j].bt<p[i].bt) 
                { 
                    temp = p[i]; 
                    p[i] = p[j]; 
                    p[j] = temp; 
                } 
            } 
            flag=1; 
        } 
        if(flag==1)
        { 
            p[i].ct = p[i-1].ct + p[i].bt; 
            ready = p[i].ct; 
            flag=0; 
        } 
        else 
        { 
            p[i].ct = p[i].at + p[i].bt; 
            ready = p[i].ct; 
        } 
    } 
} 

void tat(int n) 
{ 
    for(int i=0;i<n;i++) 
        p[i].tat = p[i].ct - p[i].at; 
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
    for(int i=0;i<n;i++) 
    { 
        printf("\nProcess P[%d]",i+1); 
        p[i].no = i+1; 
        printf("\nBurst time : "); 
        scanf("%d",&p[i].bt); 
        printf("Arrival time : "); 
        scanf("%d",&p[i].at); 
        printf("\n"); 
    } 
    printf("\nProcess\t|\tBurst time\t|\tArrival time\t|\tWaiting time\t|\tTurn around time\t|\n"); 
    sortarrival(n); 
    sjf(n); 
    tat(n); 
    wt(n); 
    for(int i=0;i<n;i++)
    { 
        printf("P[%d]\t|",p[i].no); 
        printf("\t%d\t\t|",p[i].bt); 
        printf("\t%d\t\t|",p[i].at); 
        printf("\t%d\t\t|",p[i].wt); 
        printf("\t%d\t\t\t|",p[i].tat); 
        printf("\n"); 
    } 
} 

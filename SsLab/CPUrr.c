#include<stdio.h>
#include<stdlib.h>

struct process
{
    int no;
    int bt;
    int rbt;
    int at;
    int ct;
    int wt;
    int tat;
}p[10];

int front=0,rear=-1,queue[20];

void enqueue(int num)
{
    if(rear>=19)
        printf("");
    else
        queue[++rear]=num;
}

int dequeue()
{
    int ret;
    if(front>rear)
        printf("");
    else
        ret = queue[front++];
    return ret;
}

void robin(int n,int t)
{
    struct process temp;
    int i,j,time=0,flag=1;
    for(i=0;i<n-1;i++)
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
    for(i=0;i<n;i++)
        p[i].rbt = p[i].bt;
  
    if(p[0].bt <= t)
    {
        p[0].ct = p[0].at + p[0].bt;
        time += p[0].ct;
        p[0].rbt = 0;
    }
    else
    {
        p[0].rbt -= t;
        time += t + p[0].at;
        enqueue(0);
    }
    for(i=1;i<n;)
    {  
        if(p[i].rbt <= t && p[i].rbt > 0)
        {
            time += p[i].rbt;
            p[i].rbt = 0;
            p[i].ct = time;
            if(i==queue[front])
                dequeue();
        }
        else if(p[i].rbt > t)
        {
            p[i].rbt -= t;
            time += t;
            for(j=flag+1;j<n;j++)
            {  
                if(p[j].at <= time)
                {  
                    flag=j;
                    enqueue(j);
                }
            }
            enqueue(i);
            for(int i=0;i<n;i++)
                printf("%d",queue[i]);
        }
        if(front <= rear)
            i = dequeue();
        else
            i++;
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

int main()
{
    int n,t;
    printf("\nEnter the number of processes to simulate : "); scanf("%d",&n);
    printf("\nEnter the time quantum : ");
    scanf("%d",&t);
    printf("\nEnter the burst time and arrival time of processes :\n");
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
    robin(n,t);
    tat(n);
    wt(n);
    printf("\nProcess\t|\tBurst time\t|\tArrival time\t|\tWaiting time\t|\tTurn around time\t|\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t|",p[i].no);
        printf("\t%d\t\t|",p[i].bt);
        printf("\t%d\t\t|",p[i].at);
        printf("\t%d\t\t|",p[i].wt);
        printf("\t%d\t\t\t|",p[i].tat);
        printf("\n");
    }

	return 0;
}

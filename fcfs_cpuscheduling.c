#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
int pid;
int btime;
int wtime;
int ttime;
}
p[10];
int main()
{
int i,n;
int totwtime=0,totttime=0;
printf("\n FCFS Scheduling...\n");
printf("Enter the no of process: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i].pid=1;
printf("\n Burst time of the process %d: ",i+1);
scanf("%d",&p[i].btime);
}
p[0].wtime=0;
p[0].ttime=p[0].btime;
totttime+=p[i].ttime;
for(i=1;i<n;i++)
{
p[i].wtime=p[i-1].wtime+p[i-1].btime;
totwtime+=p[i].wtime;
}
for(i=0;i<n;i++)
{
p[i].ttime=p[i].wtime+p[i].btime;
totttime+=p[i].ttime;
}
for(i=0;i<n;i++)
{{
printf("\n Waiting time for process %d: %d",i+1,p[i].wtime);
printf("\n Turn around time for process %d: %d",i+1,p[i].ttime);
printf("\n");
}}
printf("\n Total Waiting time :%d", totwtime );
printf("\n Average Waiting time :%f",(float)totwtime/n);
printf("\n Total Turn around time :%d",totttime);
printf("\n Average Turn around time: :%f",(float)totttime/n);
}

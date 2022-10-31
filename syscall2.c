#include<stdio.h>
#include<unistd.h>
main()
{
int pid,pid1,pid2;
pid=fork();
if(pid==-1)
{
printf(“ERROR IN PROCESS CREATION \n”);
exit(1);
}
if(pid!=0)
{
pid1=getpid();
printf(“\n the parent process ID is %d\n”, pid1);
}
else
{
pid2=getpid();
printf(“\n the child process ID is %d\n”, pid2);
}
}

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int pid,i;
pid=fork();
if(pid==0)
{
printf("in child\n");
for(i=0;i<=5;i++)
{
printf("%d \t",i);
}
}
else
{
printf("in Parent \n");
for(i=0;i<=5;i++)
{
printf("%d \t",i);
}
}
return 0;
}

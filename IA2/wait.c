#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
pid_t pid;
int status;
if((pid=fork())<0)
printf("fork error \n");
else if(pid==0)
{
printf("child pid is %d \n",getpid());
exit(0);//child
}
wait(&status);
system("ps ax|grep Z");
return 0;
}

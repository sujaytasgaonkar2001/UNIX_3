#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void handler(int signo)
{
printf("signal handler :Signal received by parents\n");
printf("caught signal number is %d \n",signo);
//exit(0);
}
int main()
{
pid_t pid;
pid=fork();
/*if(pid<0)
printf("fork error \n");*/
if(pid==0)
{
signal(SIGINT,handler);
sleep(2);
}
else
{
kill(pid,SIGINT);
sleep(4);
printf("parent exiting \n");
}
}

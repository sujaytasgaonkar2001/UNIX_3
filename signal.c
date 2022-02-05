#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void handler(int signo)
{
printf("\n Signal handler:caught signal num is = %d \n",signo);
exit(0);
}
void main()
{
signal(SIGINT,handler);//SIG_DFL,SIG_IGN
while(1)
printf("hello \n");
}

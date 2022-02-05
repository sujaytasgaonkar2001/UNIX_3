/*real time clock interval using alarm API*/
#include<signal.h>
#include<stdio.h>
#include "iostream"
#include<stdlib.h>
#include<unistd.h>
#define INTERVAL 1
void handler(int signo)
{
std::cout<<"alarm time out..."<<"signo is:"<<signo<<"....\n";
getchar();
}
int main()
{
struct sigaction act;
sigemptyset(&act.sa_mask);
act.sa_handler=handler;
act.sa_flags=0;
sigaction(SIGALRM,&act,0);
alarm(INTERVAL);
while(1)
std::cout<<"\n hello";
return(0);
}

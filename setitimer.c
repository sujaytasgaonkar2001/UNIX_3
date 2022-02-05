#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
#include "iostream"
#define INTERVAL 5
void handler(int signo)
{
std::cout<<"alarm time out..."<<"signo is:"<<signo;
getchar();
}
int main()
{
struct itimerval val;
struct sigaction act;
sigemptyset(&act.sa_mask);
act.sa_handler=handler;
act.sa_flags=SA_RESTART;
sigaction(SIGALRM,&act,0);//signal(SIGALRM,handler)
val.it_interval.tv_sec=INTERVAL;
val.it_interval.tv_usec=0;
val.it_value.tv_sec=INTERVAL;
val.it_value.tv_usec=0;
if((setitimer(ITIMER_REAL,&val,0))==-1)
std::cout<<"\n Settimer error  ... \n";
else
while(1)
std::cout<<"\n hello";
return 0;
}

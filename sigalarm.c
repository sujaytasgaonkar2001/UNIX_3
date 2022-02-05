#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "iostream"
void handler(int signo)
{
std::cout<<"\t Alarm timeout...signo is:"<<signo<<std::endl;
getchar();
}
int main()
{
signal(SIGALRM,handler);
alarm(1);
while(1)
std::cout<<"hello "<<std::endl;
return 0;
}

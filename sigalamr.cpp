#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream.h>
void handler(int signo)
{
cout<<"\t Alarm timeout...signo is:"<<signo<<endl;
getchar();
}
void main()
{
signal(SIGALRM,handler);
alarm(1);
while(1)
cout<<"hello \t";
}

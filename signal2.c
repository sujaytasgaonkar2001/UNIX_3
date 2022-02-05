#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void main()
{
sigset_t sigmask;
//initialize sigset
sigemptyset(&sigmask);
printf("After clearing sigset \n");
if(sigismember(&sigmask,SIGINT))
printf("Yes SIGINT is present in the list \n");
else
printf("Yes SIGINT is not present in the list \n");
/* get current sigmask*/
sigprocmask(0,0,&sigmask);
/*set SIGINT flag*/
printf("adding SIGINT to set \n");
sigaddset(&sigmask,SIGINT);
if(sigismember(&sigmask,SIGINT))
printf("Yes SIGINT is present in the list \n");
else
printf("Yes SIGINT is still not present in the list \n");
printf("clearing the sigmask completely using sigdelset \n");
sigdelset(&sigmask,SIGINT);
/*if(sigismember(&sigmask,SIGINT))
printf("yes SIGINT is present in the list \n");
else
printf("Yes SIGINT is still not present in the list \n");*/
sigfillset(&sigmask);
if(sigismember(&sigmask,SIGINT))
printf("yes SIGINT is present in the list \n");
if(sigismember(&sigmask,SIGTSTP))
printf("yes SIGTSTP is present in the list \n");
if(sigismember(&sigmask,SIGALRM))
printf("yes SIGALRM is present in the list \n");
}

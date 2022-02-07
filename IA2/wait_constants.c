#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void prexit(int status)
{
if(WIFEXITED(status))
printf("normal termination,exit status=%d \n",WEXITSTATUS(status));
else if(WIFSIGNALED(status))
printf("abnormal termination,signal number=%d%s \n",WTERMSIG(status),
#ifdef WCOREDUMP
      WCOREDUMP(status) ? " (core file generated)" : "");
#else
      "");
#endif
    else if (WIFSTOPPED(status))
       printf("child stopped,signal number=%d \n",WSTOPSIG(status));
}
void main()
{
int status;
pid_t pid;
if((pid=fork())<0)
printf("fork error");
else if(pid==0)
exit(7) ;     //child

if(wait(&status)!=pid)
printf("wait error");//wait for child
prexit(status);//and print its status*/

if((pid=fork())<0)
printf("fork error");
else if(pid==0)
abort(); //child generates SIGABORT
if(wait(&status)!=pid)
printf("wait error");//wait for child
prexit(status);//and print its status

if((pid=fork())<0)
printf("fork error");
else if(pid==0)
status/= 0;     //child /zero generates SIGFPE signal*/

if(wait(&status)!=pid)
printf("wait error");//wait for child
prexit(status);//and print its status
exit(0);
}

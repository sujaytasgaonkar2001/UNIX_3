#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<setjmp.h>
#include<stdio.h>
sigjmp_buf env;
void handler(int signo)
{
printf("signal handler:caught signal num =%d \n",signo);
siglongjmp(env,1);
}
int main()
{
int retval;
struct sigaction act;
act.sa_handler=handler;/* here your specifying the name of the signal handler*/
sigemptyset(&act.sa_mask);/*clearing the sigset*/
act.sa_flags=0; /* flag set to zero means now kernel will send SIGCHLD signal to parent in both cases of either child has been stopped or terminated*/
sigaction(SIGINT,&act,0);/*sigaction here definer SIGINT handling mechanism via &act structure variable*/
printf("pressing ctrl^c to end processing \n");
if(sigsetjmp(env,1)!=0)
 printf("return from SIGINT signal handler's siglongjmp \n" );
else
printf("return from first time sigsetjmp is called \n");
while(1);
printf("hello");
}



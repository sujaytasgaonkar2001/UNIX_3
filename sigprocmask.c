#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void catcher(int sig){
sigset_t set;
sigprocmask(SIG_SETMASK,NULL,&set);
printf("%x inside function \n",set);
}
int main()
{
sigset_t set,oset;
signal(SIGINT,catcher);
sigemptyset(&set);
sigemptyset(&oset);
printf("%x \n",set);
printf("%x \n",oset);
sigaddset(&set,SIGHUP);
sigaddset(&set,SIGTERM);
sigprocmask(SIG_SETMASK,NULL,&oset);
printf("%x \n",set);
printf("%x \n",oset);
sigprocmask(SIG_BLOCK,&set,&oset);
pause();
sigprocmask(SIG_SETMASK,&oset,&set);
printf("%x \n",oset);
}

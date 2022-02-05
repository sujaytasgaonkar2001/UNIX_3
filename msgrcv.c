#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct mbuf
{
long mtype;
char mtext[100];
}mobj={15,"hello"};
int main()
{
//int perm=S_IRUSR|S_IWUSR|S_IRGRP|S_IWOTH;
int fd=msgget(100,IPC_CREAT|0666);
if(fd==-1)
printf("error message \n");
//if(fd==-1||msgsnd(fd,&mobj,strlen(mobj.mtext),IPC_NOWAIT))
//printf("error message \n");
else if(msgrcv(fd,&mobj,100,15,MSG_NOERROR)>0)
printf("%s \n",mobj.mtext);
else
 printf("message");
return 0;
}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf
{
long mess_type;
char buf[100];
}obj;
int main()
{
int id;
id=msgget(3,IPC_CREAT|0666);
printf("msgget");
printf("before receiving the message \n");
msgrcv(id,&obj,100,2,0);
printf("data=%s \n",obj.buf);
}

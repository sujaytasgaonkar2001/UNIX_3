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
}ob1,ob2;
int main(int argc,char **argv)
{
int i,id,f1,f2;
id=msgget(20,IPC_CREAT|0666);
if(id<0)
printf("msgget failure");
ob1.mess_type=argv[1];
ob2.mess_type=3;
strcpy(ob1.buf,argv[2]);
strcpy(ob2.buf,"Water");
printf("id is %d \n",id);
msgsnd(id,&ob1,strlen(ob1.buf),0);
msgsnd(id,&ob2,strlen(ob2.buf),0);
printf("message in obj1 is %s \n",ob1.buf);
printf("message in obj2 is %s \n",ob2.buf);
if(msgrcv(id,&ob1,100,0,MSG_NOERROR)!=-1)
{
printf(" from msgrcv()-obj1 %s \n",ob1.buf);
}
if(msgrcv(id,&ob2,100,3,MSG_NOERROR)!=-1)
{
printf("from msgrcv()-obj2 %s \n",ob2.buf);
}
return 0;
}

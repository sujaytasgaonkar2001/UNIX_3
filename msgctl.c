#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(int argc,char **argv)
{
int i,id,f;
struct msqid_ds mbuf;
//int fd=msgget(20,IPC_CREAT|0666);
int fd=msgget(21,IPC_CREAT|0666);
//printf("msgget");
//obj1.mess_type=argv[1];
//strcpy(obj1.buf,argv[2]);
printf("fd i.e id is %d \n",fd);
f=msgctl(fd,IPC_STAT,&mbuf);
if(fd>0 && f!=-1)
{
printf("msg in queue = %ld \n",mbuf.msg_qnum);
}
mbuf.msg_perm.uid=getuid(); //change owner UID
if(msgctl(fd,IPC_SET,&mbuf)==-1)
{
printf(" msgctl failure error message with IPC_SET \n");
}
printf("error message \n");
if(msgctl(fd,IPC_RMID,0)==-1)
printf("error message of msgctl with cmd IPC_RMID \n");
printf("msg in queue = %ld \n",mbuf.msg_qnum);
return 0;
}

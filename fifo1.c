#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int fd1,fd2;
char buf[100];
mkfifo("f1",0666);
mkfifo("f2",0666);
fd1=open("f1",O_RDWR);
fd2=open("f2",O_RDWR);
printf("pid=%d \n",getpid());
if(fork())
{
while(1)
{
read(fd1,buf,100);
printf("the date read is %s \n",buf);
}
}
else
{
while(1)
{
printf("enter the data \n");
scanf("%s",buf);
write(fd2,buf,100);
}
}
}

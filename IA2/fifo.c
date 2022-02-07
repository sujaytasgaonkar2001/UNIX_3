#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
int fd;
char buf[256];
(void)mkfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);
if(argc==2)
{
//reader process
fd=open(argv[1],O_RDONLY|O_NONBLOCK);
while(read(fd,buf,sizeof(buf))==-1 && errno==EAGAIN)
sleep(1);
while(read(fd,buf,sizeof(buf))>0)
printf("%s",buf);
}
else
{
/*writer process*/
fd=open(argv[1],O_WRONLY);
write(fd,argv[2],strlen(argv[2]));
}
close(fd);
}

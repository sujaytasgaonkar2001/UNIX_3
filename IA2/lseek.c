#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(void)
{
int fd;
char msg1[]="the data is written from the beginning";
char msg2[]= "the data is written from the end of the file";
char msg3[]= "the data is written after 50 bytes from last write position of the file";
char ch;
fflush(stdin);
fflush(stdout);
fd=open("test.dat",O_RDWR|O_TRUNC);
/*write some data to the file from beginning,seek to beginning of file*/
lseek(fd,0,SEEK_SET);
write(fd,msg1,strlen(msg1));
/*write some data to the end of the file + after 20 bytes,seek to EOF*/
lseek(fd,20,SEEK_CUR);
write(fd,msg2,strlen(msg2));
/*read chars from the file from beginning until EOF*/
lseek(fd,50,SEEK_CUR);
write(fd,msg3,strlen(msg3));
close(fd);
return 0;
}

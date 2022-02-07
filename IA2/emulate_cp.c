#include<stdio.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
#include<unistd.h> 
void main() 
{ 
int fd1,fd2; 
char buf[60]; 
fd1=open("file3",O_RDWR); 
fd2=open("file4",O_RDWR); 
read(fd1,buf,sizeof(buf)); 
write(fd2,buf,sizeof(buf)); 
close(fd1); 
close(fd2); 
} 

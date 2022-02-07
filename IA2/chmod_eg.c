#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
struct stat statv;
if(stat("abc.c",&statv)<0)
printf("stat error for abc.c");
printf("original permissions...");
system("ls -l abc.c");
/*sets absolute mode to rw-r--r--*/
if(chmod("abc.c",S_IRUSR | S_IWUSR |S_IRGRP | S_IROTH) <0)
printf("file permissions after chmod..");
system("ls -l abc.c");
exit(0);
}

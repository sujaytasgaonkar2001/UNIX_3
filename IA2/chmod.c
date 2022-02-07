#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
void main()
{
int flag,val;
flag=(S_IWGRP | S_IROTH |S_IXOTH);
val=chmod("a4",flag);
if(val==0)
{
printf("successfull permissions changed \n");
}
else
{
printf("unsuccessfull permissions change attempt \n");
}
}


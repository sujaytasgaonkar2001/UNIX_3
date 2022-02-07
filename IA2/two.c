#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
int i;
printf("hi i am part of second program two.c \n");
printf("PID of process second process(two.c) is %d \n",getpid());
for(i=1;i<argc;i++)
   printf("argv[%d]::%s \n",i,argv[i]);
return 0;
}


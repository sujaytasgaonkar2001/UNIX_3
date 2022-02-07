#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
printf("PID of process(one.c) is %d \n",getpid());
char *args[]={"","Priyanka","Assistant Professor","CSE","BNMIT",NULL};
execv("./two",args);
printf("Back to first program. I will be printed");
}


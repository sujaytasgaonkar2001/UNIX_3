#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
int i;
char **ptr;
extern char **environ;
for(i=0;i<argc;i++)//echo all comman line args
printf("argv[%d]:%s \n",i,argv[i]);
for(ptr=environ;*ptr!=0;ptr++)/*all env strings*/
printf("%s \n",*ptr);
}

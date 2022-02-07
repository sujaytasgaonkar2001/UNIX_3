#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
char *path,*ptr;
extern char **environ;
int i=0;
/*get current path environment*/
ptr=getenv("PATH");
/*set up new path*/
path=(char *)malloc(strlen(ptr)+15);
strcpy(path,"PATH=");
strcat(path,ptr);
strcat(path,"/home/priyanka");
/*replace current path and display current environment*/
putenv(path);
while(environ[i])
printf("%s \n",environ[i++]);
return 0;
}


#include<stdio.h>
#include<string.h>
void main()
{
int n;
FILE *fd;  
char line[200];
fd=popen("ls -l",'r');// you can read from stream to retrieve the data 
while((fgets(line,200,fd))!=NULL)
printf("%s",line);
}

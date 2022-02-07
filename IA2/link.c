#include"stdio.h"
#include"unistd.h"
int main(int argc,char** argv)
{
if(argc!=3)
{
printf("insufficient no.of.arguments\n");
return 0;
}
if(link(argv[1],argv[2])==-1)
{
perror("link error");
return 1;
}
return 0;
}

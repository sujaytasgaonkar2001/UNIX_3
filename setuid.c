#include<stdio.h>
void main()
{
int real=getuid();
int euid=geteuid(); 
printf("the REAL uid is %d \n",real);
printf("the Effective uid is %d \n",euid);

}

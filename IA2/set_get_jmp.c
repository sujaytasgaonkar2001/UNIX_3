#include<stdio.h>
#include<setjmp.h>
jmp_buf var;
void hello();
void hello()
{
printf("\n hi now you are in the territory of long jump");
longjmp(var,1);
printf("statement after longjump \n");
}
int main()
{
if(setjmp(var))
printf("though i am first printf statement i did not print anything as i was called directly i will just return 0 and wait for longjump to be executed,only then i will be printing my ststements \n");
else
{
printf(" if i am executed means setjump is still waiting for longjump so now il transfer control to section which has lonjump \n");
hello();
}
return 0;
}


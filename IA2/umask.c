#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(void)
{
umask(0);//umask value is 000
if(creat("j1.c",S_IRUSR | S_IWUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |S_IWOTH) < 0) //new umask value assigned here is 666
/*calculation is as follows
old umask value                      000 000 000
1's complement of old umask  (1)     111 111 111
new umask value (2)                  110 110 110
bitwise and operation of (1) & (2)   110 110 110   (666)      */    
printf("creat error for abc.c");
umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);//again we are resetting the umask value is 066.this is as good as defining umask(066)
if(creat("j2.c",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)// now new umask for the file xyz.c is 666
/*calculation is as follows
old umask value                      000 110 110
1's complement of old umask  (1)     111 001 001
new umask value (2)                  110 110 110
bitwise and operation of (1) & (2)   110 000 000   (600)      */  
printf("creat error for xyz.c");
exit(0);
}

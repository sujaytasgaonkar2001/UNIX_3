#include <stdio.h>
 #include <stdlib.h> 
 #include <errno.h> 
 #include <fcntl.h> 
 #include <unistd.h>
/*Consider  100 bytes as a region. Write a C/C++ program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. If the region is not #locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.*/
 int  main(int  argc,  char  *argv[])
{
struct flock fl = {F_WRLCK, SEEK_SET,0, 100,0 }; int fd;
/* here flock fl = {F_WRLCK, SEEK_SET(beginning of file),0(offset from l_whence), 100(length),0 }*/
char buf[50]; 
fl.l_pid = getpid();
if  ((fd  =  open(argv[1],  O_RDWR))  ==  -1)
{
perror("Can't open file"); exit(1);
}
 if(fcntl(fd,  F_SETLK,  &fl)  ==  -1)
{
perror("Can't set Exculsive Lock");
exit(1);
}
  else if(fl.l_type != F_UNLCK)
 {
		printf("File Region has been Exclusively Locked by process:%d\n",fl.l_pid);
 }
else
{
printf("File  is  not  Locked\n");
}
printf("Press ENTER to Release lock:\n"); getchar();
fl.l_type  =  F_UNLCK;
printf("File has been Unlocked\n"); lseek(fd,50,SEEK_CUR); read(fd,buf,50);
   printf("Last 50 Byte Content in the file is\n"); printf("====================================\n"); printf("%s\n",buf);
return 0;
}

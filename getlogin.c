#define _POSIX_SOURCE
#include <stdio.h>
#include <unistd.h>
void main() 
{
  char *user;

  if ((user = getlogin()) == NULL)
    printf("__getlogin1() error");
  else printf("__getlogin() returned %s\n", user);
}

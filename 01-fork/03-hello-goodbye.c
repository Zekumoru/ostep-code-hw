/**
 * Write another program using fork(). The child process should print
 * “hello”; the parent process should print “goodbye”.
 *
 * You should try to ensure that the child process always prints first;
 * can you do this without calling wait() in the parent?
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int child = fork();

  if (child == 0)
  {
    printf("Hello!\n");
  }
  else
  {
    sleep(1);
    printf("Goodbye!\n");
  }

  return 0;
}

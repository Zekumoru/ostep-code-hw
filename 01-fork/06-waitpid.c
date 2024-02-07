/**
 * Write a slight modification of the previous program, this time using
 * waitpid() instead of wait().
 *
 * When would waitpid() be useful?
 *  - To wait for a specific child process.
 *  - There are many more reasons why it's useful but I don't
 *    comprehend it at the moment so I don't write it here.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int child = fork();

  if (child == 0)
  {
    sleep(1);
    printf("Child stuff...\n");
  }
  else
  {
    waitpid(child, NULL, 0);
    printf("Program finished!\n");
  }

  return 0;
}

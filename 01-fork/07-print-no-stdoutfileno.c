/**
 * Write a program that creates a child process, and then in the child
 * closes standard output (STDOUT FILENO).
 *
 * What happens if the child calls printf() to print some output
 * after closing the descriptor?
 *  - It doesn't output.
 *  - Though other OSes will throw an error. (As found in the internet)
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int child = fork();

  if (child == 0)
  {
    close(STDOUT_FILENO);
    printf("Some output maybe in the child?\n");
  }
  else
  {
    wait(NULL);
    printf("Program terminated.\n");
  }

  return 0;
}

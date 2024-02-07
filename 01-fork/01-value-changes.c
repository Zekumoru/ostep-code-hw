/**
 * Write a program that calls fork(). Before calling fork(), have the main
 * process access a variable (e.g., x) and set its value to something
 * (e.g., 100).
 *
 * What value is the variable in the child process?
 *  - The same as the parent.
 *
 * What happens to the variable when both the child and parent change
 * the value of x?
 *  - Changing x in the child process won't affect the x in the parent.
 *  - The address of x in both parent and child processes is the same, however,
 *    changing x in the child won't affect the x in the parent.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int x = 100;
  int *px = &x;
  int child = fork();

  if (child == 0)
  {
    *px = 200;
    printf("Child has: %d (%p)\n", x, px);
  }
  else
  {
    wait(NULL);
    printf("Parent has: %d (%p)\n", x, px);
  }

  return 0;
}

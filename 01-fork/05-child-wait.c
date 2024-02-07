/**
 * Now write a program that uses wait() to wait for the child process to
 * finish in the parent.
 *
 * What does wait() return?
 *  - The pid of the finished child.
 *
 * What happens if you use wait() in the child?
 * - Returns -1.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int child = fork();

  if (child == 0)
  {
    printf("Child stuff... (pid: %d)\n", (int)getpid());
    int pid = wait(NULL);
    printf("Attempted wait returned pid: %d\n", pid);
  }
  else
  {
    int pid = wait(NULL);
    printf("Child finished, returned pid: %d\n", pid);
  }

  return 0;
}

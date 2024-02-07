/**
 * Write a program that calls fork() and then calls some form of exec()
 * to run the program /bin/ls. See if you can try all of the variants
 * of exec(), including (on Linux) execl(), execle(), execlp(), execv(),
 * execvp(), and execvpe().
 *
 * Why do you think there are so many variants of the same basic call?
 *  - 'l' means command arguments are passed as arguments of exec
 *  - 'v' means command arguments are passed as an array (vector)
 *  - 'p' means that it will look in the environment variables to look
 *        for the command
 *  - 'e' means environment arguments
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int child = fork();

  if (child == 0)
  {
    execl("/bin/ls", ".", NULL);
  }
  else
  {
    wait(NULL);
    printf("Program terminated!");
  }

  return 0;
}

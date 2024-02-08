/**
 * Write a program that creates two children, and connects the
 * standard output of one to the standard input of the other,
 * using the pipe() system call.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

const char filename[] = "test.output";
const int strSize = 100;

void input(int in_pipe)
{
  char str[strSize];
  read(in_pipe, str, strSize);

  printf("Child %d has received message: %s\n", (int)getpid(), str);
}

void output(int out_pipe)
{
  char str[strSize];
  sprintf(str, "This message is written by child process %d!", (int)getpid());
  write(out_pipe, str, strSize);
}

int main()
{
  int pipefd[2]; // 0: read, 1: write
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  int outChild = fork();
  if (outChild == 0)
  {
    output(pipefd[1]);
    exit(0);
  }

  int inChild = fork();
  if (inChild == 0)
  {
    waitpid(outChild, NULL, 0);
    input(pipefd[0]);
    exit(0);
  }

  waitpid(inChild, NULL, 0);
  waitpid(outChild, NULL, 0);

  printf("Program terminated.\n");

  return 0;
}

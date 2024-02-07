/**
 * Write a program that opens a file (with the open() system call) and then
 * calls fork() to create a new process.
 *
 * Can both the child and parent access the file descriptor returned by open()?
 *  - Yes they can. (Assuming of course open() is called before fork())
 *
 * What happens when they are writing to the file concurrently, i.e.,
 * at the same time?
 *  - They both write their outputs. They didn't overwrite one another.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>   // To create processes with fork()
#include <sys/stat.h> // To use S_IRWXU
#include <fcntl.h>    // To use open()

char *strdup(const char str[])
{
  size_t length = 0;
  for (char ch; (ch = str[length]) != '\0'; length++)
    ;
  char *dup = malloc(length + 1);
  strcpy(dup, str);
  return dup;
}

void writeString(const char str[])
{
  char *args[3];
  args[0] = strdup("echo");
  args[1] = strdup(str);
  args[2] = NULL;
  execvp(args[0], args);
}

int main()
{
  // redirect standard output to file
  close(STDOUT_FILENO);

  const char filename[] = "02-same-file.output";
  open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  // O_CREAT: Create the file if it does not exist.
  // O_WRONLY: Write only to file.
  // O_TRUNC: Empties file (of all characters, making the file length 0).
  // S_IRWXU: The file owner (user) has read/write/execute permissions.

  int child = fork();

  if (child == 0)
  {
    writeString("Hello child!");
  }
  else
  {
    writeString("Hello parent!");
  }

  return 0;
}

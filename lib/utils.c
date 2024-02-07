#include "utils.h"
#include <stdlib.h>
#include <string.h>

char *strdup(const char str[])
{
  size_t length = 0;
  for (char ch; (ch = str[length]) != '\0'; length++)
    ;
  char *dup = malloc(length + 1);
  strcpy(dup, str);
  return dup;
}

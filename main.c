#include <stdio.h>  //printf()
#include "tokenizer.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("main function must receive a string to tokenize by ','\n");
    return 1;
  }

  char **tokens = tokenize(argv[1],",");

  for (char **p = tokens; *p; ++p)
    printf("%s\n", *p);

  return 0;
}


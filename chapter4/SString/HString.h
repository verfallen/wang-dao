#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255
//堆分配存储
typedef struct
{
  char *ch;
  int length;
} HString;

void InitString(HString &S)
{
  S.ch = (char *)malloc(MAXLEN * sizeof(char));
  S.length = 0;
}
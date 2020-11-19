#include <stdio.h>
#include "../Stack/SqStack.h"

SqStack S;

/**
 * 3.3 节 3题 调整软硬座
 * 思路：遍历队列，如果为S，入栈后立即出栈，如果为H，只入栈，待全部遍历完后出栈
*/
void trainArrange(char *train)
{
  char *p = train, c;
  SqStack S;
  InitStack(S);
  while (*p)
  {
    if (*p == 'H')
      Push(S, *p);
    else
      printf("%s", *p);

    p++;
  }

  while (!StackEmpty(S))
  {
    Pop(S, c);
    printf("%c", c);
  }
}

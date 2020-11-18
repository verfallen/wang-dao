#include <stdio.h>
#include "../Stack/SqStack.h"

SqStack S1;
SqStack S2;

/** 3.2节 3题 用两个栈模拟队列操作
 * 思路： 
 * S1作为入队的栈，S2 作为出队的栈
 * 为了保持顺序性，入栈时必须保持s2 是空的
 * 
 */
bool EnQueue(SqStack &S1, SqStack &S2, ElmeType e)
{
  ElmeType x;
  if (!StackFull(S1))
    return false;
  if (StackFull(S1) && !StackEmpty(S2))
    return false;
  if (StackFull(S1) && StackEmpty(S2))
    while (StackEmpty(S1))
    {
      Pop(S1, x);
      Push(S2, x);
    }

  Push(S1, e);
  return true;
}

void DeQueue(SqStack &S1, SqStack &S2, ElmeType &x)
{
  if (!StackEmpty(S2))
    Pop(S2, x);
  else if (StackEmpty(S1))
    printf("队列为空");
  else
  {
    while (!StackEmpty(S1))
    {
      Pop(S1, x);
      Push(S2, x);
    }

    Pop(S2, x);
  }
}

bool QueueEmpty(SqStack &S1, SqStack S2)
{
  return StackEmpty(S2) && StackEmpty(S1);
}

int main()
{
  InitStack(S1);
  InitStack(S2);
}
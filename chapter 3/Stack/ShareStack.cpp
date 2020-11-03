#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50

typedef int ElmeType;

typedef struct
{
  ElmeType data[MaxSize];
  int top0;
  int top1;
} ShareStack;

void InitStack(ShareStack &S)
{
  S.top0 = -1;
  S.top1 = MaxSize;
}

bool empty(ShareStack &S)
{
  return (bool)S.top0 == -1 && S.top1 == MaxSize;
}
bool empty0(ShareStack &S)
{
  return (bool)S.top0 == -1;
}
bool empty1(ShareStack &S)
{
  return (bool)S.top1 == MaxSize;
}

bool full(ShareStack &S)
{
  return (bool)(S.top1 - S.top0 == 1);
}

bool push0(ShareStack &S, ElmeType x)
{
  if (full(S))
    return false;
  S.data[++S.top0] = x;
  return true;
}

bool push1(ShareStack &S, ElmeType x)
{
  if (full(S))
    return false;
  S.data[--S.top1] = x;
  return true;
}

bool pop0(ShareStack &S, ElmeType &x)
{
  if (empty0(S))
    return false;
  x = S.data[S.top0--];
  return true;
}

bool pop1(ShareStack &S, ElmeType &x)
{
  if (empty1(S))
    return false;
  x = S.data[S.top1++];
  return true;
}

bool getTop0(ShareStack &S, ElmeType &x)
{
  if (empty0(S))
    return false;
  x = S.data[S.top0];
  return true;
}

bool getTop1(ShareStack &S, ElmeType &x)
{
  if (empty1(S))
    return false;
  x = S.data[S.top1];
  return true;
}
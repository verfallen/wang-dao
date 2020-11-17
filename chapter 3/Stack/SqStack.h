#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50

typedef char ElmeType;
typedef struct
{
  ElmeType data[MaxSize];
  int top;
} SqStack;

//初始化栈
void InitStack(SqStack &S)
{
  S.top = -1;
}

bool StackEmpty(SqStack &S)
{
  return (bool)S.top == -1;
}

bool StackFull(SqStack &S)
{
  return (bool)S.top == MaxSize - 1;
}

bool Push(SqStack &S, ElmeType x)
{
  if (StackFull(S))
    return false;
  S.data[++S.top] = x;
  return true;
}

bool Pop(SqStack &S, ElmeType &x)
{
  if (StackEmpty(S))
    return false;
  x = S.data[S.top--];
  return true;
}

bool GetTop(SqStack &S, ElmeType &x)
{
  if (StackFull(S))
    return false;
  x = S.data[S.top];
  return true;
}
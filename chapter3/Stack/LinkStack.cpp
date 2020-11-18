#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct Linknode
{
  ElemType data;
  struct Linknode *next;
} * LiStack;

bool InitLinkStack(LiStack &S)
{
  S = (LiStack)malloc(sizeof(Linknode));
  if (S == NULL)
    return false;

  S->next = NULL;
  return true;
}

bool StackEmpty(LiStack &S)
{
  return (bool)S->next == NULL;
}

bool Push(LiStack &S, ElemType x)
{
  Linknode *p;

  p = (Linknode *)malloc(sizeof(Linknode));
  if (p == NULL)
    return false;

  p->data = x;
  p->next = S->next;
  S->next = p;
  return true;
}

bool Pop(LiStack &S, ElemType &x)
{
  if (StackEmpty(S))
    return false;

  Linknode *p = S->next;
  S->next = p->next;
  x = p->data;
  free(p);
  return true;
}

bool GetTop(LiStack &S, ElemType &x)
{
  if (StackEmpty(S))
    return false;

  x = S->next->data;
  return true;
}

bool DestoryList(LiStack &S)
{
  while (S->next != NULL)
  {
    Linknode *p = S->next;
    S->next = p->next;
    free(p);
  }
  free(S);
  return true;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DNode
{
  int data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
  L = (DNode *)malloc(sizeof(DNode));

  if (L == NULL)
    return false;
  L->prior = NULL;
  L->next = NULL;
  return true;
}

//判断链表是否为空
bool Empty(DLinkList L)
{
  if (L->next == NULL)
    return true;
  return false;
}

DNode *GetElem(DLinkList L, int i)
{
  if (i < 0)
    return NULL;
  int j = 0;
  DNode *p;
  while (p != NULL && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

int main(int argc, char const *argv[])
{

  DLinkList L;
  InitDLinkList(L);
  return 0;
}

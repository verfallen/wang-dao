#include <stdio.h>
#include <stdlib.h>
#include "../chapter3/Queue/LinkQueueWithHead.h"

typedef int ElemType;
typedef struct ThreadNode
{
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;

//中序线索化
ThreadNode *pre = NULL;
void CreateInThread(ThreadTree T)
{
  pre = NULL;
  if (T != NULL)
  {
    InThread(T);
    if (pre->rchild == NULL)
      pre->rtag = 1;
  }
}

void visit(ThreadNode *p)
{
  if (p->lchild == NULL)
  {
    p->lchild = pre;
    p->ltag = 1;
  }

  if (pre != NULL && pre->rchild == NULL)
  {
    pre->rchild = p;
    pre->rtag = 1;
  }
  pre = p;
}

void InThread(ThreadTree T)
{
  if (T != NULL)
    InThread(T->lchild);
  visit(T);
  InThread(T->rchild);
}

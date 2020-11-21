#include <stdio.h>
#include <stdlib.h>
#include "../chapter3/Queue/LinkQueueWithHead.h"
#include "../chapter3/Stack/SqStack.h"

typedef int ElemType;
typedef struct BiTNode
{
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InitTree(BiTree &T)
{
  //插入根结点
  BiTree root = NULL;
  root = (BiTree)malloc(sizeof(BiTNode));
  root->data = 1;
  root->lchild = NULL;
  root->rchild = NULL;

  //插入新结点
  BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
  p->data = 2;
  p->lchild = NULL;
  p->rchild = NULL;
  root->lchild = p;
}


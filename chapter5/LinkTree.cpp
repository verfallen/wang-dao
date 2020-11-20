#include <stdio.h>
#include <stdlib.h>

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

void visit(BiTNode *N)
{
  printf("%s", N->data);
}

//先序遍历
void PreOrder(BiTree T)
{
  if (T != NULL)
  {
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

//中序遍历
void InOrder(BiTree T)
{
  if (T != NULL)
  {
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

//后序遍历
void PostOrder(BiTree T)
{
  if (T != NULL)
  {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}
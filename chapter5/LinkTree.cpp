#include <stdio.h>
#include <stdlib.h>
#include "../chapter3/Queue/LinkQueueWithHead.h"

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

//求深度
int Depth(BiTree T)
{
  if (T == NULL)
    return 0;
  int l = Depth(T->lchild);
  int r = Depth(T->rchild);

  return l > r ? l + 1 : r + 1;
}

/**
 * 层次遍历
 * 1. 初始化辅助队列
 * 2. 根节点入队
 * 3. 若队列非空，则队头结点出队，将其左右孩子插入队列
 * 4. 重复步骤3
 */
void LevelOrder(BiTree T)
{
  LinkQueue Q;
  InitQueque(Q);

  BiTree p;
  EnQueue(Q, T);
  while (!Empty(Q))
  {
    DeQueue(Q, p);
    visit(p);
    if (p->lchild != NULL)
      EnQueue(Q, p->lchild);
    if (p->rchild != NULL)
      EnQueue(Q, p->rchild);
  }
}

//找中序前驱节点
BiTNode *p, *pre = NULL, *final;

void findPre(BiTree T)
{
  if (T != NULL)
  {
    findPre(T->lchild);
    visit2(T);
    findPre(T->rchild);
  }
}

void visit2(BiTNode *q)
{
  if (q == p)
    final = pre;
  else
    pre = q;
}
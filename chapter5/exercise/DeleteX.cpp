#include "../LinkTree.h"
#include "../../chapter3/Queue/LinkQueueWithHead.h"

//5.3.11 删除值为x的结点，并删除它的子树
/**
 * 思路：层次遍历找到值为x的父节点p,递归删除x结点及其子树（后序）
 */

void DeleteNode(BiTNode *x)
{
  if (x != NULL)
  {
    DeleteNode(x->lchild);
    DeleteNode(x->rchild);
    free(x);
  }
}

void Search(BiTree T, ElmeType x)
{
  if (T == NULL)
    return;

  if (T->data)
  {
    DeleteNode(T);
    exit(0);
  }

  LinkQueue Q;
  InitQueque(Q);
  EnQueue(Q, T);

  BiTNode *p;
  while (!Empty(Q))
  {
    DeQueue(Q, p);
    if (p->lchild)
    {
      if (p->lchild->data == x)
      {
        DeleteNode(p->lchild);
        p->lchild = NULL;
      }
      else
        EnQueue(Q, p->lchild);
    }

    if (p->rchild)
    {
      if (p->rchild->data == x)
      {
        DeleteNode(p->rchild);
        p->rchild = NULL;
      }
      else
        EnQueue(Q, p->rchild);
    }
  }
}
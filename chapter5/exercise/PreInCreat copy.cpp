#include "../../chapter3/Queue/LinkQueueWithHead.h"
#include "../LinkTree.h"

//5.2.7 判断是否为完全二叉树
/**
 * 采用层次遍历，如果遇到空节点，查看它后面是否还有结点，如果有就不是完全二叉树
 */
bool isComplete(BiTree T)
{
  LinkQueue Q;
  InitQueque(Q);
  EnQueue(Q, T);
  BiTNode *p = T;

  while (!Empty(Q))
  {
    DeQueue(Q, p);
    if (p)
    {
      EnQueue(Q, p->lchild);
      EnQueue(Q, p->rchild);
    }
    else
    {
      while (!Empty(Q))
      {
        DeQueue(Q, p);
        if (p)
          return false;
      }
    }
  }

  return true;
}
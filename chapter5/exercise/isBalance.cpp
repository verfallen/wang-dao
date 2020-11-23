#include "../LinkTree.h"

//5.5.8 判断一棵树是否为平衡二叉树
void Judge_AVL(BiTree T, int &balance, int &h)
{
  int blaLeft = 0, blaRight = 0, lHeight = 0, rHeight = 0;
  //空结点
  if (T == NULL)
  {
    h = 0;
    balance = 1;
  }

  //叶节点
  else if (T->lchild == NULL && T->rchild == NULL)
  {
    h = 1;
    balance = 1;
  }
  else
  {
    Judge_AVL(T->lchild, blaLeft, lHeight);
    Judge_AVL(T->rchild, blaRight, rHeight);

    h = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    if (abs(lHeight - rHeight) < 2)
    {
      balance = blaLeft && blaRight;
    }
    else
    {
      balance = 0;
    }
  }
}
#include "../LinkTree.h"

//5.3.17 判断树是否相似
bool similar(BiTree T1, BiTree T2)
{
  if (T1 == NULL && T2 == NULL)
    return true;
  else if (T1 == NULL || T2 == NULL)
    return false;
  bool left = similar(T1->lchild, T2->lchild);
  bool right = similar(T1->rchild, T2->rchild);
  return left && right;
}
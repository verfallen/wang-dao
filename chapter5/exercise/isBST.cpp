#include <stdlib.h>
#include "../LinkTree.h"

//5.5.8 判断一个二叉树是否是二叉排序树
int pre = -32767;
bool JudgeBST(BiTree T)
{
  int l, r;

  if (T == NULL)
    return true;
  l = JudgeBST(T->lchild);
  if (!l || pre >= T->data)
    return false;
  pre = T->data;
  r = JudgeBST(T->rchild);
  return r;
}
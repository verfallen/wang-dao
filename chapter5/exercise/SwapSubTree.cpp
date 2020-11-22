#include "../LinkTree.h"

//5.3.9 递归交换二叉树的左右子树
void SwapSubTree(BiTree T)
{
  if (T)
  {
    SwapSubTree(T->lchild);
    SwapSubTree(T->rchild);
    BiTNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
  }
}
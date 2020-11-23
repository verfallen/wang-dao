#include "../LinkTree.h" //TODO: 替换为二叉排序树的引入

//5.3.9 求出二叉排序树中最小和最大的关键字，也就是最左和最右节点
ElemType Min(BiTree T)
{
  while (T->lchild != NULL)
    T = T->lchild;
  return T->data;
}

ElemType Max(BiTree T)
{
  while (T->rchild)
    T = T->rchild;
  return T->data;
}
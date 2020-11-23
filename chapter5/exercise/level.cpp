#include <stdlib.h>
#include "../LinkTree.h" //TODO: 替换为二叉排序树的引入

//5.5.7 求指定结点在有序二叉树中的层次
int level(BiTree T, BiTNode *p)
{
  int n = 0;
  BiTNode *t = T;
  while (T != NULL)
  {
    n++;
    while (p->data != t->data)
    {
      if (p->data < t->data)
        t = t->lchild;
      else
        t = t->rchild;
      n++;
    }
  }
  return n;
}

#include <stdlib.h>

typedef struct BiTNode
{
  int weight;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//5.3.19 求二叉树的带权路径长度
int WPL(BiTree root)
{
  return wpl_PreOrder(root, 0);
}

int wpl_PreOrder(BiTree root, int deep)
{
  static int wpl = 0;

  if (root->lchild == NULL && root->rchild == NULL)
    wpl += deep * root->weight;

  if (root->lchild != NULL)
    wpl_PreOrder(root->lchild, deep + 1);

  if (root->rchild != NULL)
    wpl_PreOrder(root->rchild, deep + 1);
  return wpl;
}
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
  ElemType data;
  struct node *child, *sibling;
} * Tree;

/**
 * 5.4.5 求以孩子兄弟表示法存储的森林的叶子节点
 * 思路：森林中的叶子结点在二叉树中就是没有左子树的结点
 * 递归遍历二叉树，如果child 指向为null,则该结点为叶子结点
 */
int Leaves(Tree T)
{
  if (T == NULL)
    return 0;
  if (T->child == NULL)
    return 1 + Leaves(T->sibling);
  return Leaves(T->child) + Leaves(T->sibling);
}
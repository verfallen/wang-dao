#include "../LinkTree.h"

/**
 * 计算二叉树的所有双分支结点
 * 思路：将树遍历一遍
 */

/**
 * 第一种方法:
 * 定义count用于计数，遍历树，如果满足条件，count +1;
 */
int count;

void visit(BiTNode *p)
{
  if (p->lchild && p->rchild)
    count++;
}
void Inorder(BiTree T)
{
  if (T != NULL)
  {
    Inorder(T->lchild);
    visit(T);
    Inorder(T->rchild);
  }
}

/**
 * 递归计算
 * 从根结点开始，递归计算该结点左右子树的双分支结点，直到为空
 */
int DsonNodes(BiTree B)
{
  if (B == NULL)
    return 0;
  if (B->lchild != NULL && B->rchild != NULL)
    return DsonNodes(B->lchild) + DsonNodes(B->rchild) + 1;
  return DsonNodes(B->lchild) + DsonNodes(B->rchild);
}
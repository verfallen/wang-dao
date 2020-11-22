#include "../LinkTree.h"

//5.2.6 根据前序序列和中序序列构建二叉链表
BiTree PreInCreat(ElmeType pre[], ElmeType in[], int pStart, int pEnd, int iStart, int iEnd)
{
  //将先序中的第一个结点作为根节点
  BiTree root = (BiTNode *)(malloc(sizeof(BiTNode)));
  root->data = pre[pStart];

  //  找到根节点在中序中的位置，其左边是左子树，右边是右子树
  int i;
  for (i = iStart; in[i] != root->data; i++)
    ;
  int llen = i - iStart;
  int rlen = iEnd - i;

  //如果左子树存在，将其递归形成一棵子树，将根节点的lchild 指针指向左子树
  if (llen)
    root->lchild = PreInCreat(pre, in, pStart + 1, pStart + llen, iStart, iStart + llen - 1);
  else
    root->lchild = NULL;

  //递归生成右子树
  if (rlen)
    root->rchild = PreInCreat(pre, in, pEnd - rlen + 1, pEnd, iEnd - rlen + 1, iEnd);
  else
    root->rchild = NULL;
  return root;
}
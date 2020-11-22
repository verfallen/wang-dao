#include "../LinkTree.h"

int count = 1;

// 5.3.10 求前序遍历第k个结点的值
ElemType PreNode(BiTree b, int k)
{
  //如果结点为空，返回特殊字符
  if (b == NULL)
    return '#';

  //如果到了第k个，返回当前结点的值
  if (count == k)
    return b->data;

  //否则计数器+1
  count++;

  //在左子树中递归寻找
  char ch = PreNode(b->lchild, k);
  //如果在左子树中找到，返回该值
  if (ch != '#')
    return ch;
  //在右子树中找
  ch = PreNode(b->rchild, k);
  return ch;
}
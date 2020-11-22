#include "../LinkTree.h"

/**5.3.5 求二叉树高度
 */

//递归算法
int BtDepth(BiTree T)
{
  if (T == NULL)
    return 0;
  int ldep = BtDepth(T->lchild);
  int rdep = BtDepth(T->rchild);

  if (ldep > rdep)
    return ldep + 1;
}

//非递归算法
/**
 * 思路：层次遍历求高度
 * 1. 使用数组模拟队列,front和rear指向对头，last 指向当前访问结点所在层的最右结点，level表示高度
 */

int Btdepth(BiTree T)
{
  if (T == NULL)
    return 0;
  int front = -1, rear = -1;
  int level = 0, last = 0;
  BiTree Q[MaxSize];
  Q[++rear] = T;

  BiTNode *p;
  while (front != rear)
  {
    p = Q[++front]; //队头元素出队

    //将左右孩子入队
    if (p->lchild)
      Q[++rear] = p->lchild;
    if (p->rchild)
      Q[++rear] = p->rchild;

    //处理最右层结点
    if (front == last)
    {
      level++;
      last = rear;
    }
  }

  return level;
}
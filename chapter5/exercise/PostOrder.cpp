#include <stdlib.h>
#include "../LinkTree.h"
#include "../../chapter3/Stack/SqStack.h"

/**
 * 非递归的后序遍历二叉树算法
 * 思路：
 * 1.pre 指向上一个结点，p指向工作结点
 * 2.从p开始，找p结点最左边的结点，将其推入栈
 *   如果最左边的结点没有右子树，访问，
 *   如果有右子树，将其推入栈中，找它的左结点
 * 3.直到已经遍历完，栈中为空
 */

void PostOrder(BiTree T)
{
  SqStack S;
  InitStack(S);

  BiTNode *p = T, *pre = NULL;

  while (p != NULL && !StackEmpty(S))
  {
    if (p)
    {
      Push(S, p);
      p = p->lchild;
    }
    else
    {
      GetTop(S, p);

      if (p->rchild != NULL && p->rchild != NULL)
      {
        p = p->rchild;
        Push(S, p);
        p = p->lchild;
      }
      else
      {
        Pop(S, p);
        printf("%c", p->data);
        pre = p;
        p = NULL;
      }
    }
  }
}
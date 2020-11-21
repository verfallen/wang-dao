#include <stdlib.h>
#include "../LinkTree.h"
#include "../../chapter3/Stack/SqStack.h"
#include "../../chapter3/Queue/SqQueue.h"

/**
 * 倒序层次遍历
 * 思路：利用栈先入后出的规则实现
 *  正序遍历，将其先入队列后入栈，最后输入，即为倒序
 */

void InvertLevel(BiTree T)
{
  BiTNode *p;

  SqQueue Q;
  SqStack S;
  InitStack(S);
  InitQueue(Q);

  EnQueue(Q, T);

  while (!Empty(Q))
  {
    DeQueue(Q, p);
    Push(S, p);

    if (p->lchild)
      EnQueue(Q, p->lchild);

    if (p->rchild)
      EnQueue(Q, p->rchild);
  }

  while (!StackEmpty(S))
  {
    Pop(S, p);
    printf("%c", p->data);
  }
}
#include "../LinkTree.h"
#include "../../chapter3/Stack/SqStack.h"

/**
 * 5.3.12 找出值为x的结点的祖先
 * 思路： 递归寻找子树为x的结点，如果找到，放入栈中
 */

SqStack S;

bool Ancestors(BiTree T, ElemType x)
{
  if (T == NULL)
    return false;
  if (T->data == x)
    return true;

  if (Ancestors(T->lchild, x) || Ancestors(T->rchild, x))
  {
    Push(S, T->data);
    return true;
  }

  return false;
}

int main()
{
  InitStack(S);
}
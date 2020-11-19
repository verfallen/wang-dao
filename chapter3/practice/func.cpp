#include <stdio.h>
#include "../Stack/SqStack.h"

/**
 * 3.3 节 4题 利用栈实现非递归计算
 * 思路：利用栈来保存n和对应的Pn(x)的值
*/

//递归算法
double func(int n, double x)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return 2 * x;
  return 2 * x * func(n - 1, x) - 2 * (n - 1) * func(n - 2, x);
}

//非递归算法
double p(int n, double x)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return 2;

  int maxSize = 50; //假设设置为50
  struct stack
  {
    int no;
    double val;
  } st[MaxSize];
  int top = -1, i;
  double fv1 = 1, fv2 = 2 * x;

  for (int i = n; i >= 2; i--) //存入2-n个元素的no
  {
    top++;
    st[top].no = i;
  }

  while (top >= 0)
  {
    st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
    fv1 = fv2;
    fv2 = st[top].val;
    top--;
  }

  return fv2;
}
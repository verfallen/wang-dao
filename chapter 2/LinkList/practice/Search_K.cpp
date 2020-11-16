#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * 2.3节 21题
 * 思路：定义p,q 两个指针 相差k，当p指向尾结点时，q指向倒数第k个结点
 */
typedef struct LNode
{
  int data;
  LNode *Link;
} LNode, *LinkList;

int Search_X(LinkList L, int k)
{
  LNode *p = L->Link, *q;
  int count = 0;

  while (p != NULL)
  {
    if (count < k)
      count++;
    else
      q = q->Link;
    p = p->Link;
  }

  if (count < k)
    return 0;
  printf("%d", q->data);
  return 1;
}
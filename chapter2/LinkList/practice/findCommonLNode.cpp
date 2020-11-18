#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "../LinkListNoHead.h"

/**
 * 2.3节 22题
 * 思路：
 * 1. 找到两个链表的长度m,n
 * 2. k =| m - n |
 * 3. 定义p,q 两个指针 相差k，当p,q指向同一个结点时，为共同后缀起始点
 */

LNode *findCommonNode(LinkList L1, LinkList L2)
{
  int len1 = Length(L1), len2 = Length(L2);
  LNode *p, *q;

  for (p = L1->next; len1 > len2; len1--)
    p = p->next;

  for (q = L2->next; len2 > len1; len2--)
    q = q->next;

  while (p->next != NULL && p->next != q->next)
  {
    p = p->next;
    q = q->next;
  }

  return p->next;
}
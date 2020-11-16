#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListNoHead.h"
using namespace std;

/** 2.3节 20 题 反复找出单循环链表里最小的结点并输出，然后删除该结点，直到单链表为空，再删除表头节点
 */

void Del_ALL(LinkList L)
{
  LNode *p, *pre;
  LNode *minp, *minpre;

  while (L->next != L)
  {
    p = L->next;
    pre = L;
    minp = p;
    minpre = pre;

    while (p != L)
    {
      if (p->data < minp->data)
      {
        minp = p;
        minpre = pre;
      }
      pre = p;
      p = p->next;
    }

    printf("%d", minp->data);
    minpre->next = minp->next;
    free(minp);
  }

  free(L);
}
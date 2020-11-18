#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct DNode
{
  int data;
  int freq = 0;
  DNode *pred, *next;
} DNode, *DLinkList;
//2.3节 21题
/**
 *  思路：
 * 先找到值为x的结点p
 * 将结点p的freq 值依次往前比较
*/
DNode *Locate(DLinkList &L, int x)
{
  DNode *p = L->next, *q;

  while (!p && p->data != x)
  {
    p = p->next;
  }

  if (p == NULL)
  {
    return NULL;
  }
  else
  {
    p->freq++;

    //摘下p结点
    p->pred->next = p->next;
    p->next->pred = p->pred;

    q = p->pred;

    //往前找，直到找到freq 值比它大的值 或者  找到头结点
    while (q != L && q->freq <= p->freq)
      q = q->pred;

    //将p结点插入到相应位置
    p->next = q->next;
    q->next->pred = p;
    p->pred = q;
    q->next = p;
  }
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListWithHead.h"
using namespace std;

//23: 删除绝对值重复的元素
void Delete(LinkList L, int n)
{
  LNode *p = L, *r;
  int q[n];

  //初始化数组元素为0
  for (int i = 0; i < n + 1; i++)
    q[i] = 0;

  while (p->next != NULL)
  {
    int m = p->next->data > 0 ? p->next->data : -p->next->data;

    //该元素值的绝对值第一次出现,将对应标志置为0
    if (q[m] == 0)
    {
      q[m] = 1;
      p = p->next;
    }
    //不是第一次出现，删除该结点
    else
    {
      r = p->next;
      p->next = r->next;
      free(r);
    }
  }
  free(q);
}
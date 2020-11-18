#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../../CircleDLinkList/CircleDLinkList.h"

using namespace std;

bool Symmetry(DLinkList L)
{
  DNode *p = L->next, *q = L->prior; // 头尾结点
  while (p != q && q->next != p)
  {
    if (p->data == q->data)
    {
      p = p->next;
      q = q->prior;
    }
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{
  DLinkList L;
  InitList(L);
  List_TailInset(L);
  PrintList(L);

  printf("%d", Symmetry(L));
}
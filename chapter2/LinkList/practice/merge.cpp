#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "../LinkListWithHead.h"

using namespace std;

//12.在递增有序的单链表中，删除数值相等的元素
void deleteSame(LinkList &L)
{
  LNode *p = L->next;
  LNode *q;

  if (p == NULL)
    return;
  while (p->next != NULL)
  {
    q = p->next;

    if (q->data == p->data)
    {
      p->next = q->next;
      free(q);
    }
    p = p->next;
  }
}

int main(int argc, char const *argv[])
{
  LinkList L;
  InitList(L);
  // List_HeadInsert(L);
  List_TailInsert(L);

  PrintList(L);

  deleteSame(L);
  PrintList(L);
  return 0;
}

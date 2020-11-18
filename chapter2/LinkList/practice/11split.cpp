#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "../LinkListWithHead.h"

using namespace std;
/**
 * 将C={a1,b1,a2,b2,,an,bn}分成两个线性表
 * A={a1,a2,a3,,an} b={bn,,b2,b1}
 */

LinkList split(LinkList &A)
{
  LinkList B = (LinkList)malloc(sizeof(LNode));
  B->next = NULL;

  LNode *p = A->next, *ra = A, *q;

  while (p != NULL)
  {
    ra->next = p;
    ra = p;
    p = p->next;
    q = p->next;

    p->next = B->next;
    B->next = p;
    p = q;
  }
  ra->next = NULL;

  return B;
}

int main(int argc, char const *argv[])
{
  LinkList L;
  InitList(L);
  // List_HeadInsert(L);
  List_TailInsert(L);

  PrintList(L);
  LinkList B;
  B = split(L);
  PrintList(L);
  PrintList(B);
  return 0;
}

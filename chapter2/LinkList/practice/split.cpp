#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "../LinkListWithHead.h"

using namespace std;
/**
 * ���������Ϊ������ͷ���ĵ�����A��B��ʹA����ԭ�������Ϊ������Ԫ�أ�ʹB���к���ԭ�����Ϊż����Ԫ��
 */

LinkList split(LinkList &A)
{
  int i = 0;
  LinkList B = (LinkList)malloc(sizeof(LNode));
  B->next = NULL;

  LNode *ra = A, *rb = B;

  LNode *p = A->next;
  A->next = NULL;

  while (p != NULL)
  {
    i++;
    if (i % 2 == 0)
    {
      rb->next = p;
      rb = p;
    }
    else
    {
      ra->next = p;
      ra = p;
    }

    p = p->next;
  }

  ra->next = NULL;
  rb->next = NULL;

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

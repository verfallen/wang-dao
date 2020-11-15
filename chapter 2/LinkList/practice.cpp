#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "LinkListNoHead.h"

using namespace std;

//1. 递归删除不带头结点单链表中所有值为x的结点
void delete_x(LinkList &L, int x)
{
  if (L == NULL)
    return;

  LNode *p;
  if (L->data == x)
  {
    p = L;
    L = L->next;
    free(p);
    delete_x(L, x);
  }
  else
  {
    delete_x(L->next, x);
  }
}

//2. 删除带结点的单链表中所有值为x的节点
void Del_x_recursion(LinkList L, int x)
{
  LNode *p = L->next;
  LNode *pre = L;
  LNode *q;

  while (p != NULL)
  {
    if (p->data == x)
    {
      q = p;
      p = p->next;
      pre->next = p;
      free(q);
    }
    else
    {
      pre = p;
      p = p->next;
    }
  }
}

int main(int argc, const char **argv)
{
  LinkList L;
  InitList(L);
  List_HeadInsert(L);
  PrintList(L);

  std::cout << "delete value 2" << std::endl;
  delete_x(L, 2);
  PrintList(L);
  return 0;
}
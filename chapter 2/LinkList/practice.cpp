#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "LinkListNoHead.h"

using namespace std;

//递归删除单链表中所有值为x的结点
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
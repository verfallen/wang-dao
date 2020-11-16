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

//3. 反向输出带头结点的单链表
void R_Print(LinkList L)
{
  if (L->next != NULL)
    R_Print(L->next);
  printf("%d", L->data);
}

//4. 删除最小值节点（带有头结点的单链表）
LinkList DeleteMin(LinkList &L)
{
  LNode *p = L->next, *pre = L;
  LNode *minp = p, *minpre = pre;

  while (p != NULL)
  {
    if (p->data < minp->data)
    {
      minp = p;
      minpre = pre;
    }
    pre = p;
    p = p->next;
  }

  minpre->next = minp->next;
  free(minp);
  return L;
}

//5.就地逆置 （带头结点的单链表）
/**
 * 有两种思路：
 * 1.头插法
 * 2.指针反向
 */
LinkList Reverse_2(LinkList L)
{
  LNode *pre, *p = L->next, *r = p->next;
  p->next = NULL;

  while (r != NULL)
  {
    pre = p;
    p = r;
    r = r->next;
    p->next = pre;
  }

  L->next = p;
  return L;
}

int main(int argc, const char **argv)
{
  LinkList L;
  InitList(L);
  List_TailInsert(L);
  PrintList(L);

  // std::cout << "delete value 2" << std::endl;
  // delete_x(L, 2);
  // PrintList(L);
  R_Print(L);
  return 0;
}
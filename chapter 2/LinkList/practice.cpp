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

//6: 递增有序（带头结点的单链表）
void Sort(LinkList L)
{
  LNode *p = L->next, *pre;
  LNode *r = r->next;
  p->next = NULL;
  p = r;

  while (p != NULL)
  {
    r = p->next;
    pre = L;

    while (pre->next != NULL && pre->next->data < p->data)
      pre = pre->next;
    p->next = pre->next;
    pre->next = p;
    p = r;
  }
}

//7. 删除介于给定两值之间的结点（带头结点的单链表）
bool RangeDelete(LinkList &L, int s, int t)
{
  if (s > t)
    return false;
  LNode *pre = L, *p = L->next;
  while (p != NULL)
  {
    if (p->data > s && p->data < t)
    {
      pre->next = p->next;
      free(p);
      p = pre->next;
    }
    else
    {

      pre = p;
      p = p->next;
    }
  }
}
//8. 找公共节点
LinkList findCommon(LinkList L1, LinkList L2)
{
  int len1 = Length(L1);
  int len2 = Length(L2);
  int dist;

  LinkList longList, shortList;
  if (len1 > len2)
  {
    longList = L1->next;
    shortList = L2->next;
    dist = len1 - len2;
  }
  else
  {
    longList = L2->next;
    shortList = L1->next;
    dist = len2 - len1;
  }

  while (dist--)
  {
    longList = longList->next;
  }

  while (longList != NULL)
  {
    if (longList == shortList)
      return longList;
    longList = longList->next;
    shortList = shortList->next;
  }
  return NULL;
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
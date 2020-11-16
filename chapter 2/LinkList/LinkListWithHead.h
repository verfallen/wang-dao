#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct LNode
{
  int data;
  LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L);
LinkList List_HeadInsert(LinkList &L);
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, int e);
int Length(LinkList L);
void PrintList(LinkList L);
bool InsertNextNode(LNode *p, int e);
bool InsertPriorNode(LNode *p, int e);

//带头结点的单链表初始化
bool InitList(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  return true;
}

//判断单链表是否为空（带头结点）
bool Empty(LinkList L)
{
  return L->next == NULL;
}

//头插法，带头结点
LinkList List_HeadInsert(LinkList &L)
{
  LNode *s;
  int x;

  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  printf("please ent num:\n");

  while (cin >> x)
  {
    s = (LNode *)(malloc(sizeof(LNode)));
    s->data = x;
    s->next = L->next;
    L->next = s;
  }
  return L;
}

//尾插法，带头结点
LinkList List_TailInsert(LinkList &L)
{
  LNode *s, *r = L;
  int x;
  printf("Please enter num:\n");

  while (cin >> x)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
  }
  r->next = NULL;
  return L;
}

// LNode *GetElem(LinkList L, int i)
// {
//   if (i < 0)
//     return NULL;
//   int j = 0; //j从0开始，这是与不带头结点的链表的区别
//   LNode *p = L;
//   while (p && j < i)
//   {
//     p = p->next;
//     j++;
//   }

//   return p;
// }

LNode *GetElem(LinkList L, int i)
{
  if (i < 0)
    return NULL;
  int j = 0;
  LNode *p = L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

LNode *LocateElem(LinkList L, int e)
{
  //区别：第一个节点为头结点的下一个节点
  LNode *p = L->next;

  while (p && p->data != e)
    p = p->next;

  return p;
}

int Length(LinkList L)
{
  int len;
  LNode *p = L->next;

  while (p)
  {
    len++;
    p = p->next;
  }

  return len;
}

void PrintList(LinkList L)
{
  LNode *p = L->next;

  while (p)
  {
    printf("%d,", p->data);
    p = p->next;
  }
  printf("\n");
}

//后插操作：在p节点之后插入元素e
bool InsertNextNode(LNode *p, int e)
{
  if (!p)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (!s)
    return false;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
  if (!p)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (!s)
    return false;
  s->next = p->next;
  p->next = s;

  s->data = p->data;
  p->data = e;
  return true;
}

//将e插入到第i个位置上，(不头结点的链表)
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  LNode *p = GetElem(L, i - 1);
  if (!p)
    return false;

  return InsertNextNode(p, e);
}

//在第i个位置插入元素e(带头结点)
bool ListInsertElement(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;

  LNode *p = L;
  int j = 0; //表示当前p指向的节点

  while (p != NULL && j < i - 1)
  {
    p = p->next;
    j++;
  }

  if (p == NULL)
    return false;

  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

//删除节点
bool DeleteNode(LNode *p)
{
  if (!p)
    return false;
  LNode *q = p->next;
  p->data = q->data;
  p->next = q->next;
  free(q);
  return false;
}

//删除链表第i个节点
bool ListDelete(LinkList &L, int i, int &e)
{
  if (i < 1)
    return false;
  LNode *p = GetElem(L, i);
  e = p->data;
  DeleteNode(p);
  return true;
}

void testHeadInsert()
{
  LinkList L;
  // InitList(L);
  List_HeadInsert(L);
  PrintList(L);
}

void testTailInsert()
{
  LinkList L;
  // InitList(L);
  List_TailInsert(L);
  PrintList(L);
}
void testListInsert(LinkList &L)
{

  ListInsert(L, 1, 8888);
  ListInsert(L, 1, 3);
  ListInsert(L, 1, 4);
  ListInsert(L, 1, 5);
  ListInsert(L, 5, 7);
  PrintList(L);

  int e;
  ListDelete(L, 1, e);
  printf("delete element: %d\n", e);
  PrintList(L);
}

//删除所有值为x的结点
void Delete_X_1(LinkList &L, int x)
{
  LNode *p = L->next;
  LNode *pre = L;
  LNode *q;

  while (p)
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
      p = p->next;
      pre = pre->next;
    }
  }
}

//反向单链表,利用递归来实现
//TODO: 为什么多输出了一个零？是因为头结点吗
void ReversePrint(LinkList L)
{

  if (L->next != NULL)
    ReversePrint(L->next);
  if (L != NULL)
  {
    printf("%d,", L->data);
  }
}

//删除最小值结点
LinkList DeleteMin(LinkList &L)
{
  LNode *pre = L->next;
  LNode *p = pre->next;
  LNode *minp = pre, *minpre;

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

// 原地算法：将单链表逆置
LinkList Reverse_1(LinkList L)
{
  LNode *p, *r;
  p = L->next;
  L->next = NULL;

  while (p != NULL)
  {
    r = p->next;
    p->next = L->next;
    L->next = p;
    p = r;
  }

  return L;
}

LinkList Reverse_2(LinkList L)
{
  LNode *pre;
  LNode *p = L->next;
  LNode *r = p->next;
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

//删除所有介于min与max之间的元素
void RangeDelete(LinkList &L, int min, int max)
{
  LNode *p = L->next;
  LNode *pre = L;

  while (p != NULL)
  {
    if (p->data > min && p->data < max)
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

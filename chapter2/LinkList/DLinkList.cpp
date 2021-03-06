#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

/**
 * 带头结点的双链表
 */
typedef struct DNode
{
  int data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList &L);
DNode *GetElem(DLinkList &L, int i);
DNode *LocateElem(DLinkList &L, int e);
bool Empty(DLinkList &L);
int Length(DLinkList &L);
void PrintList(DLinkList L);
bool InsertNextNode(DNode *p, int e);
bool InsertNextNode(DNode *p, DNode *s);
bool InsertPriorNode(DNode *p, int e);
bool DListInsert(DLinkList &L, int i, int e);
bool DeleteNode(DNode *p);
bool ListDelete(DLinkList &L, int i, int &e);
DLinkList List_HeadInsert(DLinkList &L);
DLinkList List_TailInsert(DLinkList &L);

//初始化链表
bool InitList(DLinkList &L)
{
  //1. 创建头结点
  L = (DNode *)malloc(sizeof(DNode));
  if (!L)
    return false;
  //TODO:为什么将指针指向自身
  L->prior = L;
  L->next = L;
  return true;
}

bool Empty(DLinkList L)
{
  return L->next == L && L->prior == L;
}

bool Length(DLinkList L)
{
  DNode *p = L;
  int len = 0;
  while (p->next != L)
  {
    p = p->next;
    len++;
  }

  return len;
}

DNode *GetElem(DLinkList &L, int i)
{
  if (i < 0)
    return NULL;
  int j = 0;
  DNode *p = L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

DNode *LocateElem(DLinkList &L, int e)
{
  DNode *p = L;
  if (p == NULL)
    return NULL;
  p = p->next;
  while (p && p->data != e)
    p = p->next;

  return p;
}

//头插法（带头结点）
DLinkList List_HeadInsert(DLinkList &L)
{
  int x;
  std::cout << "Enter Num" << std::endl;
  while (cin >> x)
  {

    InsertNextNode(L, x);
  }
  return L;
}

//尾插法（带头结点）
DLinkList List_TailInsert(DLinkList &L)
{
  DNode *p = L;
  int x;

  while (cin >> x)
  {
    InsertNextNode(p, x);
    p = p->next;
  }
  return L;
}

void PrintList(DLinkList L)
{
  DNode *p = L->next;
  while (p != L) //TODO: 这一步为啥？
  {
    std::cout << p->data << ",";
    p = p->next;
  }
  cout << endl;
}

//将元素值为e的节点插入到p节点之后
bool InsertNextNode(DNode *p, int e)
{
  if (!p)
    return false;
  DNode *s = (DNode *)malloc(sizeof(DNode));
  if (!s)
    return false;

  s->data = e;
  s->next = p->next;
  p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

//将s节点插入到p节点之后
bool InsertNextNode(DNode *p, DNode *s)
{
  if (!s || !p)
    return false;
  s->next = p->next;
  s->prior = p;
  if (p->next != NULL)
  {
    p->next->prior = s;
  }
  p->next = s;

  return true;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
  if (p == NULL)
    return false;
  DNode *q = p->next;
  if (q == NULL)
    return false;

  p->next = q->next;
  if (q->next != NULL)
    q->next->prior = p;
  free(q);
  return true;
}

//销毁双链表
void DestoryList(DLinkList &L)
{
  while (L->next != NULL)
  {
    DeleteNextDNode(L);
  }

  free(L);
  L = NULL;
}

bool InsertPriorNode(DNode *p, int e)
{
  if (!p)
    return false;

  InsertNextNode(p->prior, e);
  return false;
}

bool DListInsert(DLinkList &L, int i, int e)

{
  if (i <= 0)
    return false;
  DNode *p = GetElem(L, i - 1);
  if (!p)
    return false;

  return InsertNextNode(p, e);
}

bool DeleteNode(DNode *p)
{
  p->prior->next = p->next;

  if (p->next != NULL)
    p->next->prior = p->prior;
  free(p);
}

bool ListDelete(DLinkList &L, int i, int &e)
{
  if (i < 1)
    return false;
  DNode *s = GetElem(L, i);
  e = s->data;
  return DeleteNode(s);
}

void testHeadInsert()
{
  DLinkList L;
  InitList(L);
  // List_HeadInsert(L);
  // List_TailInsert(L);
  // PrintList(L);

  // DNode *p = LocateElem(L, 2);
  // InsertPriorNode(p, 1111);
  DListInsert(L, 1, 1);
  DListInsert(L, 1, 2);
  DListInsert(L, 1, 3);
  PrintList(L);
  std::cout << "delete first element" << std::endl;
  // DNode *q = GetElem(L, 2);
  // DeleteNode(q);
  int e;
  ListDelete(L, 2, e);
  std::cout << "after delete" << std::endl;
  PrintList(L);
}

int main(int argc, char const *argv[])
{
  testHeadInsert();
  // printf("output");

  return 0;
}

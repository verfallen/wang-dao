#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

/**
 * 带头结点的循环单链表
 */
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *CLinkList;

bool InitList(CLinkList &L);
LNode *GetElem(CLinkList &L, int i);
LNode *LocateElem(CLinkList &L, int e);
bool Empty(CLinkList &L);
int Length(CLinkList &L);
void PrintList(CLinkList L);
bool InsertNextNode(LNode *p, int e);
bool InsertNextNode(LNode *p, LNode *s);
bool InsertPriorNode(LNode *p, int e);
bool DListInsert(CLinkList &L, int i, int e);
bool DeleteNode(LNode *p);
bool ListDelete(CLinkList &L, int i, int &e);
CLinkList List_HeadInsert(CLinkList &L);
CLinkList List_TailInsert(CLinkList &L);

bool InitList(CLinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode *));
  if (!L)
    return false;
  L->next = L;
  return true;
}

LNode *GetElem(CLinkList L, int i)
{
  if (i < 1)
    return NULL;
  int j = 0;
  LNode *p = L;
  while (p || j < i)
  {
    p = p->next;
    j++;
  }

  return p;
}

LNode *LocateElem(CLinkList L, int e)
{
  LNode *p = L->next;

  while (p && p->data != e)
  {
    p = p->next;
  }

  return p;
}

int Length(CLinkList L)
{
  int j = 0;
  LNode *p = L->next;

  while (p)
  {
    p = p->next;
    j++;
  }

  return j;
}

void PrintList(CLinkList &L)
{
  LNode *p = L->next;

  while (p && p != L)
  {
    std::cout << p->data << ",";
    p = p->next;
  }
  cout << endl;
}

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


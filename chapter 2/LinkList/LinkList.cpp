#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
  LNode *s;
  int x;

  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  scanf("%d", &x);

  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    scanf("%d", &x);
  }

  return L;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
  LNode *s, *r = L; //r 表示尾指针
  int x;

  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;

  scanf("%d", &x);

  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
  return L;
}

//根据序号（第i个位置）查找结点
LNode *GetElem(LinkList L, int i)
{
  int j = 1;
  LNode *p = L->next;

  if (i == 0)
    return L;
  if (i < 1)
    return NULL;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }

  return p;
}

//根据值查找结点
LNode *LocateElem(LinkList L, ElemType e)
{
  LNode *p = L->next;

  while (p != NULL && p->data != e)
    p = p->next;
  return p;
}

//在第i个位置上插入结点
bool ListInsert(LinkList &L, int i, ElemType e)
{
  if (i < 1)
    return false;

  LNode *p = GetElem(L, i - 1);
  LNode *s;
  s->data = e;
  s->next = p->next;
  p->next = s;

  return true;
}

//删除第i个节点
bool ListDelete(LinkList &L, int i)
{
  if (i < 1)
    return false;
  LNode *p = GetElem(L, i - 1);
  LNode *q = p->next;
  p->next = q->next;
  free(q);

  return true;
}

int main(int argc, const char **argv)
{
  LinkList L;
  List_HeadInsert(L);
  // List_TailInsert(L);

  // LNode *p = GetElem(L, 2);
  // printf("%d:", p->data);
  return 0;
}
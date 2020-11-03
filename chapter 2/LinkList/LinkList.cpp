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

int main(int argc, const char **argv)
{
  LinkList L;
  // List_HeadInsert(L);
  List_TailInsert(L);
  return 0;
}
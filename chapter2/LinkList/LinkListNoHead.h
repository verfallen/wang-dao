#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/**
 * 不带头结点的单链表
 */

//定义结点
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L);
LinkList List_HeadInsert(LinkList &L);
void PrintList(LinkList L);

//初始化单链表
bool InitList(LinkList &L)
{
  L = NULL;
  return true;
}

/**
 * 头插法，不带头结点
 * 思路：
 * 1. 每次读入一个元素，生成一个新结点s，将读取的数据存放到新结点的数据域
 * 2. 将s的next 指针指向原来的表头
 * 3. 将s作为新的表头
 */
LinkList List_HeadInsert(LinkList &L)
{
  LNode *s;
  int x;
  printf("please ent num:\n");
  bool isHead = true;

  while (cin >> x)
  {
    if (!s)
    {
      exit(EXIT_FAILURE);
    }
    s->data = x;

    s->next = L;
    L = s;
    isHead = false;
  }
  return L;
}

/**
 * 尾插法(不带头结点)
 * r指针指向链表的尾结点
 * 1. 每次读入一个元素，生成一个新结点s，将读取的数据存放到新结点的数据域
 * 2. 如果L为空表，将L直接指向s
 * 3. 否则，将r的next指针指向s,修改尾指针
 * 需要增加一个尾指针指向
 */
LinkList List_TailInsert(LinkList &L)
{
  LNode *s, *r = L;
  int x;
  bool isHead = true;

  printf("Enter num:");
  scanf("%d", &x);

  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;

    if (isHead)
    {
      isHead = false;
      L = s;
      r = s;
    }
    else
    {
      r->next = s;
      r = s;
    }

    scanf("%d", &x);
  }

  r->next = NULL;
  return L;
}

//插入位置为i的元素
LNode *GetElem(LinkList &L, int i)
{
  if (i <= 0)
    return NULL;
  int j = 1;
  LNode *p = L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

//根据元素值定位
LNode *LocateElem(LinkList L, int e)
{
  LNode *p = L;
  while (p && p->data != e)
    p = p->next;
  return p;
}

int Length(LinkList L)
{
  int i = 0;
  LNode *p = L;
  while (p)
  {
    i++;
    p = p->next;
  }

  return i;
}

// 定位节点位置
int LocateNode(LinkList L, LNode *p)
{
  int i = 1;
  LNode *q = L;
  while (q && q != p)
  {
    q = q->next;
    i++;
  }

  int len = Length(L);

  if (i <= len)
    return i;
  return -1;
}

//后插操作
bool InsertNextNode(LNode *p, int e)
{
  LNode *s;
  s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

//前插操作
bool InsertPriorNode(LNode *p, int e)
{
  LNode *s;
  s = (LNode *)malloc(sizeof(LNode));

  s->data = e;

  s->next = p->next;
  p->next = s;

  int tmp = s->data;
  s->data = p->data;
  p->data = tmp;

  return true;
}

//将e插入到第i个位置上，(不带头结点的链表)
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  if (i == 1)
  {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s;
    return true;
  }

  LNode *p;
  p = L;
  int j = 1;
  while (p && j < i - 1)
  {
    p = p->next;
    j++;
  }

  if (!p)
    return false;
  InsertNextNode(p, e);
  return true;
}

//删除链表第i个节点
bool DeleteNode(LinkList &L, int i)
{
  int len = Length(L);

  if (i > len)
  {
    exit(EXIT_SUCCESS);
    return errno;
  }

  //找到被删除节点的前驱节点
  LNode *p = GetElem(L, i - 1);
  LNode *q = p->next;
  p->next = q->next;
  free(q);
  return true;
}

void PrintList(LinkList L)
{
  int j = 1;
  LNode *p = L;
  while (p)
  {
    printf("%d,", p->data);
    p = p->next;
  }
  printf("\n");
}

void testInsertHead(LinkList &L)
{
  List_HeadInsert(L);
  PrintList(L);
}

void testTailInsert(LinkList &L)
{
  List_TailInsert(L);
  PrintList(L);
}

void testInsertAndDelte(LinkList &L)
{
  printf("length is %d\n", Length(L));

  ListInsert(L, 1, 1);
  ListInsert(L, 1, 2);
  ListInsert(L, 1, 3);
  ListInsert(L, 1, 4);
  ListInsert(L, 1, 10);

  printf("length is %d\n", Length(L));
  PrintList(L);

  DeleteNode(L, 3);
  PrintList(L);
}

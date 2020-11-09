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

//��ͷ���ĵ������ʼ��
bool InitList(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  return true;
}

//ͷ�巨����ͷ���
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

//β�巨����ͷ���
LinkList List_TailInsert(LinkList &L)
{
  LNode *s, *r = L;
  int x;
  printf("Please enter num:\n");
  scanf("%d", &x);

  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  return L;
}

// LNode *GetElem(LinkList L, int i)
// {
//   if (i < 0)
//     return NULL;
//   int j = 0; //j��0��ʼ�������벻��ͷ�������������
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
  //���𣺵�һ���ڵ�Ϊͷ������һ���ڵ�
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

//����������p�ڵ�֮�����Ԫ��e
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

//ǰ���������p���֮ǰ����Ԫ��e
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

//��e���뵽��i��λ���ϣ�(��ͷ��������)
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

//ɾ���ڵ�
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

//ɾ�������i���ڵ�
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

//ɾ������ֵΪx�Ľ��
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

//��������,���õݹ���ʵ��
//TODO: Ϊʲô�������һ���㣿����Ϊͷ�����
void ReversePrint(LinkList L)
{

  if (L->next != NULL)
    ReversePrint(L->next);
  if (L != NULL)
  {
    printf("%d,", L->data);
  }
}

//ɾ����Сֵ���
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

int main(int argc, char const *argv[])
{
  // testHeadInsert();
  // testTailInsert();

  LinkList L;
  InitList(L);
  List_HeadInsert(L);
  PrintList(L);

  DeleteMin(L);
  // Delete_X_1(L, 1);
  PrintList(L);
  // testListInsert(L);

  return 0;
}

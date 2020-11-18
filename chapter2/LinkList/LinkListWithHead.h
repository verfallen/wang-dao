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

//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩
bool Empty(LinkList L)
{
  return L->next == NULL;
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

  while (cin >> x)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
  }
  r->next = NULL; //���һ�����Ҫָ��null
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

// void PrintList(LinkList L)
// {
//   LNode *p = L->next;

//   while (p != NULL)
//   {
//     printf("%d,", p->data);
//     p = p->next;
//   }
//   printf("\n");
// }

void PrintList(LinkList L)
{
  LNode *s = L->next;
  while (s != NULL)
  {
    cout << s->data << " ";
    s = s->next;
  }
  cout << endl;
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

//�ڵ�i��λ�ò���Ԫ��e(��ͷ���)
bool ListInsertElement(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;

  LNode *p = L;
  int j = 0; //��ʾ��ǰpָ��Ľڵ�

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

// ԭ���㷨��������������
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

//ɾ�����н���min��max֮���Ԫ��
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

/**
 * 9. ��������������������еĽ��Ԫ��
 * ˼·������n�Σ�ÿ���ҳ���Сֵ�Ľ�㣬����ɾ��
 */
void Min_Delete(LinkList &head)
{
  LNode *p;
  LNode *minpre;
  while (head->next != NULL) //����ֻʣͷ���
  {
    minpre = head;
    p = head->next;
    while (p->next != NULL)
    {
      if (p->next->data < minpre->next->data)
      {
        minpre = p;
      }
      p = p->next;
    }

    printf("%d", minpre->next->data);
    LNode *q = minpre->next;
    minpre->next = q->next;
    free(q);
  }
  free(head);
}

// int main(int argc, char const *argv[])
// {
//   // testHeadInsert();
//   // testTailInsert();

//   LinkList L;
//   InitList(L);
//   List_HeadInsert(L);
//   List_TailInsert(L);
//   // PrintList(L);

//   // DeleteMin(L);
//   // Delete_X_1(L, 1);
//   // LinkList L1;
//   // L1 = Reverse_2(L);
//   // Sort(L);
//   // RangeDelete(L, 0, 5);
//   // PrintList(L);
//   // testListInsert(L);

//   Min_Delete(L);
//   return 0;
// }

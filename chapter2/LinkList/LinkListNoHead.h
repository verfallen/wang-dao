#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/**
 * ����ͷ���ĵ�����
 */

//������
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L);
LinkList List_HeadInsert(LinkList &L);
void PrintList(LinkList L);

//��ʼ��������
bool InitList(LinkList &L)
{
  L = NULL;
  return true;
}

/**
 * ͷ�巨������ͷ���
 * ˼·��
 * 1. ÿ�ζ���һ��Ԫ�أ�����һ���½��s������ȡ�����ݴ�ŵ��½���������
 * 2. ��s��next ָ��ָ��ԭ���ı�ͷ
 * 3. ��s��Ϊ�µı�ͷ
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
 * β�巨(����ͷ���)
 * rָ��ָ�������β���
 * 1. ÿ�ζ���һ��Ԫ�أ�����һ���½��s������ȡ�����ݴ�ŵ��½���������
 * 2. ���LΪ�ձ���Lֱ��ָ��s
 * 3. ���򣬽�r��nextָ��ָ��s,�޸�βָ��
 * ��Ҫ����һ��βָ��ָ��
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

//����λ��Ϊi��Ԫ��
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

//����Ԫ��ֵ��λ
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

// ��λ�ڵ�λ��
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

//������
bool InsertNextNode(LNode *p, int e)
{
  LNode *s;
  s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

//ǰ�����
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

//��e���뵽��i��λ���ϣ�(����ͷ��������)
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

//ɾ�������i���ڵ�
bool DeleteNode(LinkList &L, int i)
{
  int len = Length(L);

  if (i > len)
  {
    exit(EXIT_SUCCESS);
    return errno;
  }

  //�ҵ���ɾ���ڵ��ǰ���ڵ�
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

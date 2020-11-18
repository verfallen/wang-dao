#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/**
 * 循环双链表
 */
typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	DNode *next, *prior;
} DNode, *DLinkList;

bool InsertNextDNode(DNode *p, DNode *s);
bool InsertNextNode(DNode *p, ElemType e);
//初始化循环双链表
bool InitList(DLinkList &L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = L;
	L->next = L;
	return true;
}

//判空
bool Empty(DLinkList L)
{
	return L->next == L;
}

//判断结点是否为表尾结点
bool isTail(DLinkList L, DNode *p)
{
	return p->next == L;
}

//在结点p之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool InsertNextDNode(DNode *p, ElemType e)
{
	if (p == NULL)
		return false;
	DNode *s = (DNode *)malloc(sizeof(DNode));
	if (s == NULL)
		return false;

	s->data = e;
	return InsertNextDNode(p, s);
}

//删除p的后继结点q
bool DeleteNextDNode(DNode *p)
{
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true;
}

DLinkList List_TailInset(DLinkList &L)
{
	DNode *r = L->next, *s;
	ElemType x;
	while (cin >> x)
	{
		s = (DNode *)malloc(sizeof(DNode));
		s->data = x;
		InsertNextDNode(r, s);
		// r->next = s;
		// s->next = r->next;
		// s->prior = r;
	}
	return L;
}

void PrintList(DLinkList L)
{
	DNode *p = L->next;
	while (!isTail(L, p))
	{
		printf("%d,", p->data);
	}
	printf("\n");
}
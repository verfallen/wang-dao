#include <stdio.h>
#include <stdlib.h>
/**
 * 循环双链表
 */
typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	DNode *next, *prior;
} DNode, *DLinkList;

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
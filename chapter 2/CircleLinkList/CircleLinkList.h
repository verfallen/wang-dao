#include <stdio.h>
#include <stdlib.h>
/**
 * 循环单链表
 **/
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

//初始化循环单链表
bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

//判断循环单链表是否为空
bool Empty(LinkList L)
{
	return L->next == L;
}

//判断结点p是否为表尾结点
bool isTail(LinkList L, LNode *p)
{
	return p->next == L;
}

void PrintList(LinkList L)
{
	LNode *p = L->next;

	while (p->next != L)
		printf("%d,", p->data);

	printf("\n");
}
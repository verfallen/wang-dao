#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListWithHead.h"
using namespace std;

//将两个递增的单链表合并为一个递减的单链表
void mergeList(LinkList &A, LinkList &B)
{
	LNode *pa = A->next;
	LNode *pb = B->next;
	A->next = NULL;
	LNode *r;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			r = pa->next;

			pa->next = A->next;
			A->next = pa;
			pa = r;
		}
		else
		{
			r = pb->next;

			pb->next = A->next;
			A->next = pb;
			pb = r;
		}
	}

	if (pa)
	{
		pb = pa;
	}

	while (pb)
	{
		r = pb->next;
		pb->next = A->next;
		A->next = pb;
		pb = r;
	}

	free(B);
}

int main(int argc, char const *argv[])
{
	//TODO:未运行测试
	LinkList LA;
	LinkList LB;
	InitList(LA);
	InitList(LB);
	List_TailInsert(LA);
	PrintList(LA);

	List_HeadInsert(LB);
	PrintList(LB);

	mergeList(LA, LB);
	PrintList(LA);
	return 0;
}

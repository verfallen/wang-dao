#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListWithHead.h"
using namespace std;

//15.从A,B两个递增单链表查找交集，存放于A链表中
LinkList findCommon(LinkList &A, LinkList &B)
{
	LNode *pa = A->next, *pb = B->next, *r = A, *q;

	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
			q = pb;
			pb = pb->next;
			free(q);
		}
		else if (pa->data < pb->data)
		{
			q = pa;
			pa = pa->next;
			free(q);
		}
		else
		{
			q = pb;
			pb = pb->next;
			free(q);
		}
	}

	while (pa)
	{
		q = pa;
		pa = pa->next;
		free(q);
	}

	while (pb)
	{
		q = pb;
		pb = pb->next;
		free(q);
	}

	r->next = NULL;
	free(B);
	return A;
}

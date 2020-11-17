#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListWithHead.h"
using namespace std;

//从两个递增单链表中提取公共结点
LinkList findCommon(LinkList &A, LinkList &B)
{
	LNode *pa = A->next;
	LNode *pb = B->next;
	LinkList C = (LNode *)malloc(sizeof(LNode));
	LNode *rc = C;
	LNode *s;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pb = pb->next;
		}
		else
		{
			s = (LNode *)malloc(sizeof(LNode));
			s->data = pa->data;
			rc->next = s;
			rc = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	rc->next = NULL;
	return C;
}

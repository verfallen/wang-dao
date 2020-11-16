#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListWithHead.h"
using namespace std;

//16： 判断B是否是序列A的子序列(假设A，B都无头结点)
int Pattern(LinkList A, LinkList B)
{
	LNode *pa = A, *pb = B, *pre = pa;

	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pa = pa->next;
			pb = pb->next;
		}
		else
		{
			pre = pre->next;
			pa = pre;
			pb = B;
		}
	}

	if (pb == NULL)
		return 1;
	return 0;
}
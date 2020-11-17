#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include "../LinkListNoHead.h"
using namespace std;

/**18.两个循环单链表h1,h2  将链表h2连接到链表h1之后
 * 思路：找到h1,h2的尾结点
 * 将h1的尾结点的next 指向h2
 * 将h2 的尾结点的next 指针指向h1
 */

LinkList Link(LinkList &h1, LinkList &h2)
{
  LNode *p = h1, *q = h2;
  while (p->next != h1)
    p = p->next;

  while (q->next != h2)
    q = q->next;

  p->next = h2;
  q->next = h1;
  return h1;
}


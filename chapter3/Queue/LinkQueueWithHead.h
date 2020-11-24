#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;
/**
 * 带头结点的链队
 * rear 指向最后一个节点
 */

typedef int ElemType;
typedef struct LinkNode
{
  ElemType data;
  struct LinkNode *next;
} LinkNode;

typedef struct
{
  LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q);
bool Empty(LinkQueue Q);
bool EnQueue(LinkQueue &Q, ElemType x);
bool DeQueue(LinkQueue &Q, ElemType &x);

void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  Q.front->next = NULL;
}

bool Empty(LinkQueue Q)
{
  return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, ElemType x)
{
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;

  Q.rear->next = s;
  Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x)
{
  if (Empty(Q))
    return false;
  LinkNode *p = Q.front->next;
  x = p->data;
  Q.front->next = p->next;
  if (Q.rear == p)
    Q.rear = Q.front;
  free(p);
  return true;
}
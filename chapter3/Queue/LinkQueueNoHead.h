#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;
/**
 * 不头结点的链队
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

void InitQueque(LinkQueue &Q);
bool Empty(LinkQueue Q);
bool EnQueue(LinkQueue &Q, ElemType x);
bool DeQueue(LinkQueue &Q, ElemType &x);

void InitQueque(LinkQueue &Q)
{
  Q.front = Q.rear = NULL;
}

bool Empty(LinkQueue Q)
{
  return Q.front == NULL;
}

bool EnQueue(LinkQueue &Q, ElemType x)
{
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;

  if (Empty(Q))
  {
    Q.front = s;
    Q.rear = s;
  }
  else
  {
    Q.rear->next = s;
    Q.rear = s;
  }
}

bool DeQueue(LinkQueue &Q, ElemType &x)
{
  if (Empty(Q))
    return false;
  LinkNode *p = Q.front;
  x = p->data;
  Q.front = p->next;

  if (Q.rear == p)
  {
    Q.front = NULL;
    Q.rear = NULL;
  }
  else
    free(p);
  return true;
}
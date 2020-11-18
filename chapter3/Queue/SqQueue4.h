#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10

typedef int ElemType;

/**
 * front 指向队头元素
 * rear 指向队尾元素
 */
typedef struct
{
  ElemType data[MaxSize];
  int front, rear;
} SqQueue;

void InitList(SqQueue &Q)
{
  Q.front = 0;
  Q.rear = MaxSize - 1;
}

bool Empty(SqQueue &Q)
{
  //队尾指针的下一个位置是否是队头
  return (Q.rear + 1) % MaxSize == Q.front;
}

//判满
bool Full(SqQueue &Q)
{
  //队尾指针的下2个位置是否是队头，这是牺牲一个单元的做法
  return (Q.rear + 2) % MaxSize == Q.front;
}

//入队
bool EnQueue(SqQueue &Q, ElemType e)
{
  if (Full(Q))
    return false;
  Q.rear = (Q.rear + 1) % MaxSize;
  Q.data[Q.rear] = e;
  return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &e)
{
  if (Empty(Q))
    return false;
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

//获取队头元素
bool GetHead(SqQueue Q, ElemType &x)
{
  if (Empty(Q))
    return false;
  x = Q.data[Q.front];
  return true;
}

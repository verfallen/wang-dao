#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10

typedef int ElemType;

/**
 * front 指向队头元素
 * rear 指向队尾元素可插入的下一个位置
 * tag 表示最近执行的操作为删除 0 或者 插入1
 */
typedef struct
{
  ElemType data[MaxSize];
  int front, rear;
  int tag;
} SqQueue;

void InitList(SqQueue &Q)
{
  Q.front = Q.rear = 0;
  Q.tag = 0;
}

bool Empty(SqQueue &Q)
{
  return Q.front == Q.rear && Q.tag == 0;
}

//判满
bool Full(SqQueue &Q)
{
  return Q.rear == Q.front && Q.tag == 1;
}

//入队
bool EnQueue(SqQueue &Q, ElemType e)
{
  if (Full(Q))
    return false;
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize;
  Q.tag = 1;
  return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &e)
{
  if (Empty(Q))
    return false;
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  Q.tag = 0;
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

//获取队列长度
int Length(SqQueue Q)
{
  return (Q.rear + MaxSize - Q.front) % MaxSize;
}
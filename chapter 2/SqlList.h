#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 100

typedef int ElementType;

//动态分配
typedef struct
{
  ElementType *data;
  int MaxSize;
  int length;
} SqlList;

//初始化顺序表
void InitSqlList(SqlList &L)
{
  L.data = (ElementType *)malloc(sizeof(ElementType) * (InitSize));
  L.length = 0;
  L.MaxSize = InitSize;
}

//打印表元素
void PrintList(SqlList &L)
{
  int length = L.length;
  for (int i = 0; i < length; i++)
  {
    printf("%d,", L.data[i]);
  }
  printf("\n");
}

//在第i个位置插入新元素e
bool ListInsert(SqlList &list, int i, ElementType e)
{
  if (i < 1 || i > list.length + 1)
    return false;
  if (list.length >= list.MaxSize)
    return false;
  for (int j = list.length; j >= i; j--)
    list.data[j] = list.data[j - 1];
  list.data[i - 1] = e;
  list.length++;

  return true;
}

int LocateElem(SqlList &L, ElementType e)
{
  for (int i = 0; i < L.length; i++)
    if (L.data[i] == e)
      return i;

  return -1;
}

ElementType GetElem(SqlList &list, int i)
{
  if (i < 1 || i > list.length)
    return false;
  return list.data[i - 1];
}

//删除表中第i个位置的元素
bool ListDelete(SqlList &L, int i, ElementType &e)
{
  if (i < 1 || i > L.length)
    return false;
  e = L.data[i - 1];
  for (int j = i; j < L.length; j++)
  {
    L.data[j - 1] = L.data[j];
  }
  L.length--;
  return true;
}
// 返回表的长度
int Length(SqlList &l)
{
  return l.length;
}

//判空
bool Empty(SqlList &L)
{
  return Length(L) == 0;
}

void DestoryList(SqlList &L)
{
  free(L.data);
}

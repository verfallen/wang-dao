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

//打印表元素
void PrintList(SqlList &L)
{
  int length = Length(L);
  for (int i = 0; i < length; i++)
  {
    printf("[%d]:%d\n", i, L.data[i]);
  }
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

// 习题2.1 删除最小值的元素并返回该元素，空出的位置由最后一个元素填补
bool DelMin(SqlList &L, ElementType &value)
{
  if (Empty(L))
    return false;
  value = L.data[0];

  int pos;
  for (int i = 1; i < L.length; i++)
  {
    if (value > L.data[i])
    {
      value = L.data[i];
      pos = i;
    }
  }
  L.data[pos] = L.data[L.length - 1];
  L.length--;
  return true;
}
  SqlList L;
  InitSqlList(L);

  ListInsert(L, 1, 1);
  ListInsert(L, 2, 2);
  ListInsert(L, 3, 3);
  ListInsert(L, 4, 5);
  ListInsert(L, 5, 2);
  PrintList(L);

  ElementType delElem;
  ListDelete(L, 2, delElem);
  printf("The second element is:%d\n", delElem);
  printf("After delete the second:\n");
  PrintList(L);

  printf("%d\n", LocateElem(L, 5));
  printf("L is empty?%d", Empty(L));

  return 0;
}

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
    printf("%d,", L.data[i]);
  }
  printf("\n");
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

//习题2.2 第二小题：元素逆置
void Reverse(SqlList &L)
{
  ElementType tmp;
  int len = L.length;
  for (int i = 0; i < len / 2; i++)
  {
    tmp = L.data[i];
    L.data[i] = L.data[len - 1 - i];
    L.data[len - 1 - i] = tmp;
  }
}

// 3. 删除所有值为x的元素
void DelX(SqlList &list, ElementType x)
{
  int num = 0;
  for (int i = 0; i < list.length; i++)
  {
    if (list.data[i] == x)
      num++;
    else
      list.data[i - num] = list.data[i];
  }

  list.length = list.length - num;
}

void testDelMin(SqlList &L)
{

  ElementType min;
  PrintList(L);
  DelMin(L, min);
  printf("min element is %d\n", min);
  PrintList(L);
}

void testReverse(SqlList &L)
{
  PrintList(L);
  Reverse(L);
  printf("After Reverse:\n");
  PrintList(L);
}

void testDelX(SqlList &L)
{
  PrintList(L);
  DelX(L, 2);
  printf("After delete 2:\n");
  PrintList(L);
}

int main()
{

  SqlList L; //L.data ={10,20,3,-5,2,1}
  InitSqlList(L);
  ListInsert(L, 1, 10);
  ListInsert(L, 2, 20);
  ListInsert(L, 3, 3);
  ListInsert(L, 4, -5);
  ListInsert(L, 5, 2);
  ListInsert(L, 5, 1);
  ListInsert(L, 5, 2);
  // testDelMin();

  // testReverse(L);
  testDelX(L);

  return 0;
}

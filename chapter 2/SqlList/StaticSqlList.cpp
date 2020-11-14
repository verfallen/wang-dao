#include <stdio.h>

#define MaxSize 10

typedef struct
{
  int data[MaxSize];
  int length;
} SqList;

void InitList(SqList &L)
{
  // for (int i = 0; i < MaxSize; i++)
  // L.data[i] = 0;
  L.length = 0;
}

void PrintList(SqList L)
{
  for (int i = 0; i < L.length; i++)
    printf("%d", L.data[i]);
  printf("\n");
}

//插入到位序i
bool ListInsert(SqList &L, int i, int e)
{
  if (i < 1 || i > L.length + 1)
    return false;
  if (L.length >= MaxSize)
    return false;
  for (int j = L.length - 1; j >= i; j)
    L.data[j] = L.data[j - 1]; //元素后移
  L.data[i - 1] = e;
  L.length++;
  return true;
}

//删除第i个位置的元素
bool ListDelete(SqList &L, int i, int &e)
{
  if (i < 1 || i > L.length + 1)
    return false;
  e = L.data[i - 1];
  for (int j = i; j < L.length; j++)
    L.data[j - 1] = L.data[j]; //元素前移
  L.length--;
  return true;
}

//按位查找
int GetElem(SqList L, int i)
{
  return L.data[i - 1];
}

int main(int argc, char const *argv[])
{
  SqList L;
  InitList(L);
  ListInsert(L, 1, 1);
  ListInsert(L, 1, 2);
  ListInsert(L, 1, 3);

  PrintList(L);

  int e = -1;

  // if (ListDelete(L, 3, e))
  // {
  //   printf("删除第3个元素，为%d", e);
  // }
  return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include "SqlList.h"

// 6.在有序顺序表中删除值重复的元素
bool DelDuplicate(SqlList &L)
{
  if (L.length == 0)
    return false;
  int i, j;

  for (i = 0, j = 1; j < L.length; j++)
    if (L.data[i] != L.data[j])
      L.data[++i] = L.data[j];

  L.length = i + 1;

  return true;
}

void testDelDuplicate(SqlList &L)
{
  DelDuplicate(L);
  printf("After delete:\n");
  PrintList(L);
}

int main()
{
  SqlList L; //L.data ={10,20,3,-5,2,1}
  InitSqlList(L);
  ListInsert(L, 1, 0);
  ListInsert(L, 2, 2);
  ListInsert(L, 2, 2);
  ListInsert(L, 2, 2);
  ListInsert(L, 5, 3);
  ListInsert(L, 6, 5);
  ListInsert(L, 7, 5);
  ListInsert(L, 8, 7);
  ListInsert(L, 9, 8);
  ListInsert(L, 10, 10);
  PrintList(L);

  testDelDuplicate(L);

  return 0;
}
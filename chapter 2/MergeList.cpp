#include <stdio.h>
#include <stdbool.h>
#include "SqlList.h"

// 7.将两个有序列表合并为一个有序列表
bool MergeList(SqlList A, SqlList B, SqlList &C)
{
  int i = 0, j = 0, k = 0;
  if (A.length + B.length > C.MaxSize)
    return false;

  while (i < A.length && j < B.length)
    if (A.data[i] <= B.data[j])
      C.data[k++] = A.data[i++];
    else if (A.data[i] > B.data[j])
      C.data[k++] = B.data[j++];

  while (i < A.length)
    C.data[k++] = A.data[i++];
  while (j < B.length)
    C.data[k++] = B.data[j++];

  C.length = k;
  return true;
}

void testMergeList(SqlList &L)
{
  printf("After merge:\n");
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
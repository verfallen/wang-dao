#include "../SqlList/SqlList.h"

/**
 * 2.逆置顺序表
 * 思路：交换第i个和 n-1-i个元素的位置
 */

void swap(int &a, int &b)
{
  int tmp = b;
  b = a;
  a = tmp;
}

void Reverse(SqlList &L)
{
  for (int i = 0; i < L.length / 2; i++)
  {
    swap(L.data[i], L.data[L.length - i - 1]);
  }
}
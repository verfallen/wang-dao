#include <iostream>
using namespace std;
#include "../SqlList/SqlList.h"

/**
 * 3.删除值为x的元素
 * 思路：
 * k 记录表中x的个数
 * 依次遍历顺序表，检查元素值是否等于x,如等于 k++;
 * 在遍历过程过检查k,只要k>0,将元素值依次往左移k位，直到遍历完成
 */
void DeleteX(SqlList &L, int x)
{
  int k = 0;
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == x)
      k++;
    else
      L.data[i - k] = L.data[i];
  }
  L.length -= k;
}

#include "../SqlList/SqlList.h"

/**
 * 1.删除最小元素并返回被删除的值，空出的位置由最后一个元素填补
 * 思路：
 * 检查表是否为空，如果为空，则退出
 * 检索数据，min记录最小值的元素下标
 */
bool deleteMin(SqlList L, int &e)
{
  if (L.length == 0)
  {
    exit(EXIT_FAILURE);
    return false;
  }

  int i, min;
  for (i = 1, min = 0; i < L.length; i++)
  {
    if (L.data[i] < L.data[min])
      min = i;
  }

  L.data[min] = L.data[L.length - 1];
  L.length--;
  return true;
}
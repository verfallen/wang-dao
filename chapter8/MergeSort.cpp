#include <stdlib.h>
/**
 * 归并排序
 * 思路：
 * 分别归并排序A[]的左右部分，最后将两部分合并
 */

/**
 * 合并函数：
 * 增加B[]作为辅助数组，复制A[]中从low~high所有的元素
 * 分别设两个指针i和j,指向low和mid+1
 * 比较B[i]，B[j],将较小的填入A[k]
 * 将剩余的元素依次放入A[]中
 */
void Merge(int A[], int low, int mid, int high)
{
  int i, j, k;

  int *B = (int *)malloc(sizeof A);
  for (k = low; k <= high; k++)
    B[k] = A[k];

  k = i;
  i = low;
  j = mid + 1;
  while (i <= mid && j <= high)
  {
    if (B[i] <= B[j])
      A[k] = B[i++];
    else
      A[k] = B[j++];
    k++;
  }

  while (i <= mid)
    A[k++] = B[i++];
  while (j <= high)
    A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    Merge(A, low, mid, high);
  }
}
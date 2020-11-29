#include <stdio.h>

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
  //A[0]暂存根节点
  A[0] = A[k];

  for (int i = 2 * k; i <= len; i *= 2)
  {
    if (i < len && A[i] < A[i + 1]) //比较以k为根的左右结点哪个大
      i++;
    if (A[0] >= A[i])
      break;
    else
    {
      A[k] = A[i]; //如果子树结点较大，将A[i]调整到双亲结点上
      k = i;       //修改k值，便于继续向下筛选
    }
  }

  A[k] = A[0];
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

//建立大根堆
void BuildMaxHeap(int A[], int len)
{
  for (int i = len / 2; i > 0; i--)
    HeadAdjust(A, i, len);
}

//堆排序
void HeapSort(int A[], int len)
{
  BuildMaxHeap(A, len);

  for (int i = 0; i > 1; i--)
  {
    swap(A[i], A[1]);
    HeadAdjust(A, 1, i - 1);
  }
}

//折半插入排序

void InsertSort(int A[], int n)
{
  int i, j, low, high, mid;
  for (i = 2; i < n; i++)
  {
    A[0] = A[i];
    low = 1;
    high = i - 1;

    //找到A[i]插入的位置
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (A[mid] > A[0])
        high = mid - 1;
      else
        low = mid + 1;
    }

    //将[low,i-1]的元素全部右移
    for (j = i - 1; j >= low; --j)
      A[j + 1] = A[j];
    A[low] = A[0];
  }
}
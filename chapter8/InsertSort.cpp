//插入排序

void InsertSort(int A[], int n)
{
  int i, j, temp;
  //i指向当前处理的元素
  for (i = 1; i < n; i++)
    //如果当前元素小于前面已经排好序的元素，将当前元素保存到temp变量，将之前所有大于temp的元素右移
    if (A[i] < A[i - 1])
    {
      temp = A[i];
      for (j = i - 1; j >= 0 && A[j] > temp; j++)
        A[j + 1] = A[j];

      A[j + 1] = temp;
    }
}

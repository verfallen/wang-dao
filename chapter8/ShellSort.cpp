//希尔排序
void ShellSort(int A[], int n)
{
  //d 为划分子表长度；
  int d, i, j;
  for (d = n / 2; d >= 1; d = d / 2)
  {
    for (i = d + 1; i <= n; i++)
    {
      if (A[i] < A[i - d])
      {
        A[0] = A[i];
        for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
          A[j + d] = A[j];
        A[j + d] = A[0];
      }
    }
  }
}
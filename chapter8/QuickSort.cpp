//快速排序

void QuickSort(int A[], int low, int high)
{
  if (low < high)
  {
    int p = Partition(A, low, high);
    QuickSort(A, low, p - 1);
    QuickSort(A, p + 1, high);
  }
}

//划分
int Partition(int A[], int low, int high)
{
  int pivot = A[low];

  while (low < high)
  {
    while (low < high && A[high] >= pivot)
      --high;
    A[low] = A[high];
    while (low < high && A[low] <= pivot)
      ++low;
    A[high] = A[low];
  }

  A[low] = pivot;
  return low;
}
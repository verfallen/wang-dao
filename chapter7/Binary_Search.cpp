//折半查找(对升序列表)

int Binary_Search(int num[], int n, int key)
{
  int low = 0, high = n - 1, mid;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (num[mid] > key)
      low = mid + 1;
    else if (num[mid] < key)
      high = mid - 1;
    else
      return mid;
  }

  return -1;
}
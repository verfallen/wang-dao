//折半查找(递归算法)

int BinSearchRec(int num[], int key, int low, int high)
{
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (key > num[mid])
    BinSearchRec(num, key, mid + 1, high);
  else if (key < num[mid])
    BinSearchRec(num, key, low, mid - 1);
  else
    return mid;
}

//7.2.7   找到值为k的结点，将它与前驱结点交换
int SeqSearch(int nums[], int n, int k)
{
  int i = 0;
  while (nums[i] != k && i < n)
    i++;
  if (i < n && i > 0)
  {
    int temp = nums[i];
    nums[i] = nums[i - 1];
    nums[i - 1] = temp;
    return --i;
  }

  return -1;
}
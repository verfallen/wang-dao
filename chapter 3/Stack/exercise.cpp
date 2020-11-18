#include <stdio.h>
#include <stdbool.h>

//3.1节 应用题3.2  判定给定的操作序列是否合法
bool Judge(char str[])
{
  int iNum = 0;
  int oNum = 0;
  int i = 0;

  while (str[i] != '\0')
  {
    if (str[i] == 'I')
      iNum++;
    if (str[i] == 'O')
      oNum++;

    i++;
    if (oNum > iNum)
      return false;
  }

  if (oNum < iNum)
    return false;
  return true;
}

bool Judge2(char A[])
{
  int i = 0, count = 0;

  while (A[i] != '\0')
  {
    if (A[i] == 'I')
      count++;
    if (A[i] == 'O')
      count--;

    if (count < 0)
      return false;
    i++;
  }

  if (count != 0)
    return false;
  return true;
}
int main(int argc, const char **argv)
{
  char str[] = "III0IOIO";
  printf("the result is :%d", Judge(str));

  return 0;
}
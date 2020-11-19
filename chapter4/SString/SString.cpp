#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

#define MAXLEN 255

//数组下标从1开始，目的是为了让数组下标和字符位序一致
typedef struct
{
  char ch[MAXLEN];
  int length;
} SString;

void InitString(SString &S)
{
  S.length = 0;
}

bool StrAssign(SString &S, char chars[])
{
  S.length = 0;
  for (int i = 1; chars[i]; i++)
  {
    S.ch[i] = chars[i];
    S.length++;
  }
  return true;
}

bool StrCopy(SString &T, SString S)
{
  T = S;
  return true;
}

bool StrEmpty(SString &S)
{
  return S.length == 0;
}

int StrCompare(SString S, SString T)
{
  int i = 1;
  while (i < S.length && i < T.length)
  {
    if (S.ch[i] != T.ch[i])
      return S.ch[i] - T.ch[i];
    i++;
  }

  return S.length - T.length;
}

int StrLength(SString S)
{
  return S.length;
}

bool SubString(SString &Sub, SString S, int pos, int len)
{
  if (pos + len - 1 > S.length)
    return false;

  for (int i = 1; i < len; i++)
    Sub.ch[i] = S.ch[pos + i];

  Sub.length = len;

  return true;
}

bool Concat(SString &T, SString S1, SString S2)
{

  for (int i = 1; i <= S1.length; i++)
  {
    T.ch[i] = S1.ch[i];
  }

  for (int j = 1; j <= S2.length; j++)
  {
    T.ch[S1.length + j] = S2.ch[j];
  }

  T.length = S1.length + S2.length;

  return true;
}

void PrintString(SString S)
{
  for (int i = 0; i < S.length; i++)
  {
    printf("%c", S.ch[i]);
  }
  printf("\n");
}

//S为主串，T为待匹配的串
int Index(SString S, SString T)
{
  int tLen = T.length;
  int sLen = S.length;
  int i = 1;
  SString sub;
  InitString(sub);

  while (i <= sLen - tLen + 1)
  {
    SubString(sub, S, i, tLen);
    if (StrCompare(sub, T) != 0)
    {
      i++;
    }
    else
    {
      return i;
    }
  }
  return -1;
}

//请空栈只做逻辑删除
bool ClearString(SString &S)
{
  S.length = 0;
  return true;
}

//销毁栈释放空间
bool DestroyString(SString &S)
{
  free(S.ch);
  return true;
}
//暴力匹配算法 O(mn)
int Index2(SString S, SString T)
{
  int i = 1;
  int j = 1;

  while (i <= S.length && j <= T.length)
  {
    if (S.ch[i] == T.ch[i])
    {
      i++;
      j++;
    }
    else
    {
      i = i - j + 2;
      i = 1;
    }
    if (j > T.length)
      return i - T.length;
    return -1;
  }
}

int main(int argc, const char **argv)
{
  SString S;
  InitString(S);
  char str[] = "Hello World";
  char s2[] = "";
  char s3[] = "hello World";
  StrAssign(S, str);
  PrintString(S);

  SString T;
  StrCopy(T, S);
  PrintString(T);

  // StrAssign(S, "ABCD");
  // PrintString(S);
  // PrintString(T);

  StrAssign(S, s2);
  // std::cout << StrEmpty(S) << std::endl;

  StrAssign(S, s3);
  PrintString(S);

  std::cout << StrCompare(S, T) << std::endl; //TODO: 返回值不对
  std::cout << 'h' - 'H' << std::endl;

  SString Sub;
  InitString(Sub);
  SubString(Sub, T, 4, 5);
  PrintString(Sub);

  // SString H;
  // InitString(H);
  // Concat(H, Sub, T);
  // PrintString(H);

  std::cout << Index(T, Sub) << std::endl;
  return 0;
}
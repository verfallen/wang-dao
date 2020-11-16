#include <stdlib.h>

#define MaxSize 50
/**
 * 静态链表
 */
typedef int ElemType;
typedef struct
{
  ElemType data;
  int next;
} SLinkList[MaxSize];

void InitList(SLinkList &L)
{
  L->next = -1;
}

int main(int argc, char const *argv[])
{
  SLinkList L;
  InitList(L);

  return 0;
}

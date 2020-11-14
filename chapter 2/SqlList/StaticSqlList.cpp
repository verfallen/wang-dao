#include <stdio.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L)
{
    // for (int i = 0; i < MaxSize; i++)
    // L.data[i] = 0;
    L.length = 0;
}

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d", L.data[i]);
    printf("\n");
}

//插入到位序i
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length - 1; j >= i; j)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

int main(int argc, char const *argv[])
{
    SqList L;
    InitList(L);
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    return 0;
}

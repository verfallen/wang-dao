#include <stdio.h>

#define MaxSize 100

typedef char ElmeType;

//数组存储下标从1开始
typedef struct TreeNode
{
  ElmeType value;
  bool isEmpty;
} TreeNode, *SqTree;

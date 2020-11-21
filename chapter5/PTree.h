#include <stdlib.h>

#define MAX_TREE_SIZE 100
typedef int ElemType;

//双亲表示法
typedef struct
{
  ElemType data;
  int parent;
} PTNode;

typedef struct
{
  PTNode nodes[MAX_TREE_SIZE];
  int n;
} PTree;
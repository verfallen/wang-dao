//孩子表示法（顺序+链式存储）

#define MAX_TREE_SIZE 50

typedef int ElemType;

struct CTNode
{
  int child;
  struct CTNode *next;
};

typedef struct
{
  ElemType data;
  struct CtNode *firstChild;
} CTBox;

typedef struct
{
  CTBox nodes[MAX_TREE_SIZE];
  int n, r;
} CTree;
/**
 * 孩子兄弟表示法（链式存储）
 * 原则：左孩子右兄弟
 */
typedef int ElemType;

typedef struct CSNode
{
  ElemType data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
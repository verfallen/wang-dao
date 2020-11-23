#include <stdlib.h>

typedef struct AVLNode
{
  int key;
  int balance;
  struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;
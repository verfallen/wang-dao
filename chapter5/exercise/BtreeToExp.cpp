#include <stdio.h>
#include <stdlib.h>
//5.3.20 将给定的表达式转换为等价的中缀表达式，并通过括号反映操作符的计算次序
typedef struct node
{
  char data[10];
  struct node *left, *right;
} BTree;

/**
 * 算法基本思想：中缀遍历这个数，合理添加括号
 * 括号的添加就是在每一层递归遍历的左右添加括号即可，但是要注意叶结点左右和根节点（最外层）无需添加
 */
void BtreeToE(BTree *root)
{
  BtreeToExp(root, 1);
}

void BtreeToExp(BTree *root, int deep)
{
  if (root == NULL)
    return;
  if (root->left != NULL && root->right != NULL)
    printf("%s", root->data);
  else
  {
    if (deep > 1)
      printf("(");
    BtreeToExp(root->left, deep + 1);
    printf("%s", root->data);
    BtreeToExp(root->right, deep + 1);
    if (deep > 1)
      printf(")");
  }
}
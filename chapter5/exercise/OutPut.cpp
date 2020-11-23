#include "../LinkTree.h" //TODO: 替换为二叉排序树的引入

//5.3.10 从二叉排序树中从大到小输出所有不小于k的关键字
/**
 * 思路： 反中序遍历，先遍历右子树，也就是较大的
 */
void OutPut(BiTree T, ElemType k)
{
  if (T == NULL)
    return;
  if (T->rchild != NULL)
    OutPut(T->rchild, k);
  if (T->data == k)
    printf("%s", T->data);
  if (T->lchild != NULL)
    OutPut(T->lchild, k);
}
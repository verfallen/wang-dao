#include <stdlib.h>
/**
 * 二叉排序树
 */
typedef struct BSTNode
{
  int key;
  struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//在二叉排序树中查找值为key的结点
BSTNode *BST_Search(BSTree T, int key)
{
  while (T == NULL && key != T->key)
    if (key < T->key)
      T = T->lchild;
    else
      T = T->rchild;

  return T;
}

//在二叉排序树中查找值为key的结点(递归实现)
BSTNode *BSTSearch(BSTree T, int key)
{
  if (T == NULL)
    return NULL;
  if (T->key == key)
    return T;
  if (key < T->key)
    return BSTSearch(T->lchild, key);
  return BSTSearch(T->rchild, key);
}

//在二叉排序树中插入关键字为k的新结点（递归实现）
bool BST_Insert(BSTree &T, int key)
{
  if (T == NULL)
  {
    T = (BSTree)malloc(sizeof(BSTNode));
    T->key = key;
    T->lchild = T->rchild = NULL;
    return true;
  }
  if (key == T->key)
    return 0;
  if (key < T->key)
    return BST_Insert(T->lchild, key);
  return BST_Insert(T->rchild, key);
}

//按照给定序列构建二叉排序树
void Creat_BST(BSTree &T, int num[], int n)
{
  T = NULL;
  int i = 0;
  while (i < n)
  {
    BST_Insert(T, num[i]);
    i++;
  }
}

/**
 * 删除值为key 的结点
 * 思路：
 * 1. 找到该结点，如果为空，返回false
 * 2. 如果为叶子结点，直接删除
 * 3. 如果左右子树只有一个，将其子树放在被删除结点的父节点上
 * 4. 否则，用其右子树中最小的结点替代
 */
bool BST_Delete(BSTree &T, int key)
{
  BSTNode *p = BST_Search(T, key);
}
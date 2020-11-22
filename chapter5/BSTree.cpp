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
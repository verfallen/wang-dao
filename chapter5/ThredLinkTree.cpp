#include <stdio.h>
#include <stdlib.h>
#include "../chapter3/Queue/LinkQueueWithHead.h"

typedef int ElemType;
typedef struct ThreadNode
{
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;

//中序线索化，在中序便利的过程中进行线索化
ThreadNode *pre = NULL;
void CreateInThread(ThreadTree T)
{
  pre = NULL;
  if (T != NULL)
  {
    //中序遍历二叉树
    InThread(T);
    //处理遍历的最后一个结点
    if (pre->rchild == NULL)
      pre->rtag = 1;
  }
}

//访问时进行线索化
void visit(ThreadNode *p)
{
  //如果当前结点的左指针为空，指向前一个结点
  if (p->lchild == NULL)
  {
    p->lchild = pre;
    p->ltag = 1;
  }

  //  如果pre 结点的右指针为空，指向当前结点
  if (pre != NULL && pre->rchild == NULL)
  {
    pre->rchild = p;
    pre->rtag = 1;
  }
  pre = p;
}

void InThread(ThreadTree T)
{
  if (T != NULL)
  {
    InThread(T->lchild);
    visit(T);
    InThread(T->rchild);
  }
}

/**
 * 王道书上的中序线索化(同上种方法思路一样)
 * 思路：pre指向前一个访问过得结点，p指向当前访问的结点
 * 如果p的 左指针为空，将其指向pre
 * 如果pre 的右指针为空，将其指向p
 */
void InThread2(ThreadTree p, ThreadTree &pre)
{
  if (p != NULL)
  {
    InThread2(p->lchild, pre);
    if (p->lchild == NULL)
    {
      p->lchild = pre;
      p->ltag = 1;
    }

    if (pre != NULL && pre->rchild == NULL)
    {
      pre->rchild = p;
      pre->rtag = 1;
    }

    pre = p;
    InThread2(p->rchild, pre);
  }
}

void CreateInThread2(ThreadTree T)
{
  ThreadTree pre = NULL;
  if (T != NULL)
  {
    //中序遍历二叉树
    InThread2(T, pre);
    //处理遍历的最后一个结点
    if (pre->rchild == NULL)
      pre->rtag = 1;
  }
}

//用于线索化的visit
void Visit(ThreadNode *p)
{
  if (p != NULL)
  {
    if (p->lchild == NULL)
    {
      p->lchild = pre;
      p->ltag = 1;
    }

    if (pre != NULL && pre->rchild == NULL)
    {
      pre->rchild = p;
      pre->rtag = 1;
    }

    pre = p;
  }
}

//先序遍历二叉树
void PreThread(ThreadTree T)
{
  if (T != NULL)
  {
    Visit(T);
    if (T->ltag == 0)
      PreThread(T->lchild);
    if (T->rtag == 0)
      PreThread(T->rchild);
  }
}

//先序线索化
void CreateInThread(ThreadTree T)
{
  pre = NULL;
  if (T != NULL)
  {
    PreThread(T);
    if (pre->rchild != NULL)
      pre->rtag = 1;
  }
}
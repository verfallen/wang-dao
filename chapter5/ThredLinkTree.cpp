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
void Visit(ThreadNode *p)
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
    Visit(T);
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

/**
 * 在线索二叉树中找前驱，后继
 */

ThreadNode *Firstnode(ThreadNode *p);

//在中序线索二叉树中找到p的后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
  if (p->rtag == 0)
    return Firstnode(p->rchild);
  return p->rchild;
}

//找到以p为根节点，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
  while (p->ltag == 0)
    p = p->lchild;
  return p;
}

//对中序线索二叉树进行中序遍历
void InOrder(ThreadNode *T)
{
  ThreadNode *p = Firstnode(T);

  while (p != NULL)
  {
    printf("%s", p->data);
    p = Nextnode(p);
  }
}

//找到以p为子结点的树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p);

//在中序线索二叉树中找到p的前驱结点
ThreadNode *Prenode(ThreadNode *p)
{
  if (p->ltag == 0)
    return Lastnode(p->lchild);
  return p->lchild;
}

ThreadNode *Lastnode(ThreadNode *p)
{
  while (p->rtag == 0)
    p = p->rchild;

  return p;
}

//对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadNode *T)
{
  ThreadNode *p = Lastnode(T);

  while (p != NULL)
  {
    printf("%c", p);
    p = Prenode(p);
  }
}
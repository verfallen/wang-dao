#include "../LinkTree.h"

//5.3.15 给出满二叉树的先序序列，求后序序列
void PreToPost(ElemType pre[], int pStart, int pEnd, ElemType post[], int poStart, int poEnd)
{
  int half;
  if (pEnd >= pStart)
  {
    post[poEnd] = pre[pStart];
    half = (pEnd - pStart) / 2;
    PreToPost(pre, pStart + 1, pStart + half, post, poStart, poStart + half - 1);
    PreToPost(pre, pStart + half + 1, pEnd, post, poStart + half, poEnd - 1);
  }
}
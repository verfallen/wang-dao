#include "../Graph.h"
#include "../../chapter3/Stack/SqStack.h"

bool visited[];
SqStack S;

void visit(int k);
//深度优先搜索的非递归算法

void DFS_Non_RC(ALGraph &G, int v)
{
  int w;
  int k;

  InitStack(S);

  for (int i = 0; i < G.vexnum; i++)
    visited[i] = false;

  Push(S, v);
  visited[v] = true;

  while (!StackEmpty(S))
  {
    Pop(S, k);
    visit(k);

    for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
      if (!visited[w])
      {
        Push(S, w);
        visited[w] = true;
      }
  }
}

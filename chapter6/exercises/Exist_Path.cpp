#include "../Graph.h"
#include "../../chapter3/Queue/LinkQueueWithHead.h"

//查找以邻接表方式存储的有向图中是否存在i到j的路径

//深度优先写法
bool visited[MaxVertexNum] = {false};

bool Exist_Path_DFS(ALGraph G, int i, int j)
{
  int p;

  if (i == j)
    return true;
  visited[i] = true;
  for (p = FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p))
    if (!visited[p] && Exist_Path_DFS(G, p, j))
      return true;

  return false;
}

//广度优先写法

LinkQueue Q;
int Exist_Path_BFS(ALGraph G, int i, int j)
{
  InitQueue(Q);
  EnQueue(Q, i);

  while (!Empty(Q))
  {
    int u;
    DeQueue(Q, u);
    visited[u] = true;
    for (int p = FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, u, p))
    {
      int k = G.vertices[p].first->adjvex; //找到该结点的邻接表

      if (k == j)
        return true;
      if (!visited[k])
        EnQueue(Q, k);
    }
  }
  return false;
}
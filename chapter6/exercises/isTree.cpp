#include "../Graph.h"

bool visited[];
/**
 * 判断无向图G 是否是一棵树
 * 思路：采用深度优先搜索算法在遍历的过程中统计可能访问到的顶点的个数和边的条数，如果一次遍历就能访问到n个顶点和n-1条边，则可以判定是一棵树
 */

bool isTree(ALGraph &G)
{
  for (int i = 0; i < G.vexnum; i++)
    visited[i] = false;

  int Vnum = 0, Enum = 0;

  DFS(G, 1, Vnum, Enum, visited);

  return Vnum == G.vexnum && Enum == 2 * (G.arcnum - 1);
}

void DFS(ALGraph &G, int v, int &Vnum, int &Enum, bool visited[])
{
  visited[v] = true;
  Vnum++;

  int w = FirstNeighbor(G, v);
  while (w != -1)
  {
    Enum++;
    if (!visited[w])
      DFS(G, w, Vnum, Enum, visited);
    w = NextNeighbor(G, v, w);
  }
}
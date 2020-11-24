#include "./Graph.h";

/**
 * 深度优先遍历
 */
//标记访问数组
bool visited[MaxVertexNum];

void DFSTraverse(ALGraph G)
{
  int i;
  //初始化访问数组,从1开始
  for (i = 1; i < G.vexnum; i++)
    visited[i] = false;

  for (i = 1; i < G.vexnum; i++)
    if (!visited[i])
      DFS(G, i);
}

void DFS(ALGraph G, int v)
{
  visit(v);
  visited[v] = true;
  for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
    if (!visited[w])
      DFS(G, w);
}

//访问顶点
void visit(int x);
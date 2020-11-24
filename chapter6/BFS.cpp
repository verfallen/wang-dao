#include "./Graph.h";
#include "../chapter3/Queue/LinkQueueWithHead.h"

/**
 * 深度优先算法
 */

bool visited[MaxVertexNum];
LinkQueue Q;
void BFSTraverse(ALGraph G)
{
  InitQueue(Q);
  for (int i = 0; i < G.vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G.vexnum; i++)
    if (!visited[i])
      BFS(G, i);
}

void BFS(ALGraph G, int v)
{
  //访问第一个结点并标记
  visit(v);
  visited[v] = true;

  //将第一个结点入队
  EnQueue(Q, v);
  while (!Empty(Q))
  {
    DeQueue(Q, v);

    //找出与v的临接点
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
    {
      if (!visited[w])
      {
        visit(w);
        visited[w] = true;
        EnQueue(Q, w);
      }
    }
  }
}

void visit(int v){};
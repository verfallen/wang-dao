#include <limits.h>
#include "./Graph.h"
#include "../chapter3/Queue/LinkQueueWithHead.h"
/**
 * BFS 求无权图的单源最短路径
 */

bool visited[MaxVertexNum];

int d[MaxVertexNum];    //保存到u的最短路径长度
int path[MaxVertexNum]; //最短路径从哪个顶点过来

void BFS_MIN_Distance(ALGraph G, int u)
{
  for (int i = 0; i < G.vexnum; i++)
  {
    d[i] = INT_MAX;
    path[i] = -1;
  }

  d[u] = 0;
  visited[u] = true;
  EnQueue(Q, u);

  while (!Empty(Q))
  {
    DeQueue(Q, u);
    for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, v, w))
    {
      if (!visited[w])
      {
        d[w] = d[u] + 1;
        path[w] = u;
        visited[w] = true;
        EnQueue(Q, w);
      }
    }
  }
}
#include "./Graph.h"
#include "../chapter3/Stack/SqStack.h"
/**
 * 拓扑排序
 * 1. 用一个栈存储入度为0的顶点
 * 2. indegree 数组记录当前顶点的入度
 * 3. print[] 记录拓扑序列，count 记录当前已经输出的顶点数
 * 思路：
 * 每次都将入度为0的顶点保存到栈里，直到检索完毕或者发现环导致退出程序
 */
SqStack S;

int indegree[];
int print[] = {-1};

bool TopologicalSort(ALGraph G)
{
  InitStack(S);
  int i;
  for (i = 0; i < G.vexnum; i++)
  {
    if (indegree[i] == 0)
      Push(S, i);

    int count = 0;
    while (!StackEmpty(S))
    {
      Pop(S, i);
      print[count++] = i;

      //将所有i指向的顶点的入度-1，并将入度为0的再次压入栈中
      for (ArcNode *p = G.vertices[i].first; p != NULL; p = p->next)
      {
        int v = p->adjvex;
        if (--indegree[v] == 0)
          Push(S, v);
      }

      if (count < G.vexnum)
        return false;
      return true;
    }
  }
}
//图的临接表法

#define MaxVertexNum 100

//边
typedef struct ArcNode
{
  int adjvex;
  struct ArcNode *next;
} ArcNode;

//用邻接表存储的图
typedef struct
{
  AdjList verices;
  int vexnum, arcnum;
} ALGraph;

//顶点
typedef struct VNode
{
  char data;      //顶点数据
  ArcNode *first; //顶点指向的边
} VNode, AdjList[MaxVertexNum]
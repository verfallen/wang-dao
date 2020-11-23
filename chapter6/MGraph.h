//图的邻接矩阵存储

#define MaxVertexNum 100
typedef struct
{
  char Vex[MaxVertexNum];               //存放顶点信息
  int Edge[MaxVertexNum][MaxVertexNum]; //存放边的信息
  int vexnum, arcnum;                   //图的当前顶点数和边数
} MGraph
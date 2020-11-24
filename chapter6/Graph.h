#define MaxVertexNum 100

//边表结点
typedef struct ArcNode
{
  int adjvex;
  struct ArcNode *next;
} ArcNode;

//顶点
typedef struct VNode
{
  char data;
  ArcNode *first;
} VNode, AdjList[MaxVertexNum];

//邻接表
typedef struct
{
  AdjList vertices;
  int vexnum, arcnum;
} ALGraph;

//判断图G是否在边<x,y>;
bool Adjacent(ALGraph G, char x, char y);

// 列出图G 中与结点x邻接的边
ArcNode *Neighbors(ALGraph G, char x);

//在图中插入顶点x
bool InsertGraph(ALGraph G, char x);

//在图中删除顶点x
bool DeleteVertex(ALGraph G, char x);

//添加边<x,y>
bool AddEdge(ALGraph G, char x, char y);

//删除边<x,y>
bool RemoveEdge(ALGraph G, char x, char y);

//返回顶点x的第一个邻接点的顶点号
int FirstNeighbor(ALGraph G, char x);

//返回除y之后x的下一个邻接点的顶点号
int NextNeighbor(ALGraph G, int x, int y);

//获取<x,y>对应的权值
int Get_edge_value(ALGraph G, int x, int y);

//设置<x,y>对应的权值为v
void Set_edge_value(ALGraph G, int x, int y, int v);

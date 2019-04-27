#include <stdio.h>
#define MaxVertexNum 10

//邻接矩阵表示图
typedef int Vertex, WeightType;
typedef char DataType; 
typedef struct GNode {
	int vexnum, arcnum; //顶点个数，及边数
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum] ;
} *PtrToGNode;
typedef PtrToGNode MGragh;

MGragh CreateGraph(int VertexNum) {
	Vertex V, W;
	MGragh Graph;
	Graph = (MGragh)malloc(sizeof(struct GNode));
	Graph->vexnum = VertexNum;
	Graph->arcnum = 0;

	//注意：这里默认顶点编号为0开始，到Graph->vexnum-1;
	for (V = 0; V < Graph->vexnum; V++)
		for (W = 0; W < Graph->vexnum; W++)
			Graph->G[V][W] = 0;
	return Graph;
}

//向MGraph插入边
typedef struct ENode {
	Vertex V1, V2;  //边的两个顶点
	WeightType Weight;  //权重
}*PtrToENode;
typedef PtrToENode Edge;
void InsertEdge(MGragh Graph, Edge E) {
	//插入边 <V1,V2> 
	Graph->G[E->V1][E->V2] = E->Weight;

	//若为无向图，则还要插入边<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}
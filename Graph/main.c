#include <stdio.h>
#define MaxVertexNum 10

//�ڽӾ����ʾͼ
typedef int Vertex, WeightType;
typedef char DataType; 
typedef struct GNode {
	int vexnum, arcnum; //���������������
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

	//ע�⣺����Ĭ�϶�����Ϊ0��ʼ����Graph->vexnum-1;
	for (V = 0; V < Graph->vexnum; V++)
		for (W = 0; W < Graph->vexnum; W++)
			Graph->G[V][W] = 0;
	return Graph;
}

//��MGraph�����
typedef struct ENode {
	Vertex V1, V2;  //�ߵ���������
	WeightType Weight;  //Ȩ��
}*PtrToENode;
typedef PtrToENode Edge;
void InsertEdge(MGragh Graph, Edge E) {
	//����� <V1,V2> 
	Graph->G[E->V1][E->V2] = E->Weight;

	//��Ϊ����ͼ����Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}
#pragma once

typedef char T;
#define DEFAULT_VERTEX_SIZE  20

struct GraphMtx {
	int MaxVertices;  //最大顶点数
	int NumVertices;  //当前顶点数
	int NumEdges;     //边数

	T* VerticesList;  //顶点链表
	int** Edge;       //边值矩阵
};

void InitGraph(GraphMtx& g);
void DestroyGraph(GraphMtx& g);

void InsertVertex(GraphMtx& g, T v);
int GetVertexPos(const GraphMtx& g, T v);
void InsertEdge(GraphMtx& g, T v1, T v2);
void RemoveEdge(GraphMtx& g, T v1, T v2);
void RemoveVertex(GraphMtx& g, T v);
void ShowGraph(const GraphMtx& g);

/* 取第一个邻接顶点 */
int GetFirstNeighbor(const GraphMtx& g, T v);
/* v的某一个邻接顶点的是w，取w后一个顶点 */
int GetNextNeighbor(const GraphMtx& g, T v, T w);
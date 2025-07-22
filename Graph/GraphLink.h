#pragma once

typedef char T;
#define DEFAULT_VERTEX_SIZE  20

struct Edge {
	int dest;   //顶点下标
	Edge* link; //连接
};
struct Vertex {
	T data;
	Edge* adj;  //顶点和第一条边
};
struct GraphLink {
	int MaxVertices;  //最大顶点数
	int NumVertices;  //当前顶点数
	int NumEdges;     //边数
	Vertex* NodeTable;  //顶点列表
};

void InitGraph(GraphLink& g);
void DestroryGraph(GraphLink& g);

void InsertVertex(GraphLink& g, T v);
int GetVertexPos(const GraphLink& g, T v);
void InsertEdge(GraphLink& g, T v1, T v2);
void RemoveEdge(GraphLink& g, T v1, T v2);
void RemoveVertex(GraphLink& g, T vertex);
void ShowGraph(const GraphLink& g);

/* 取第一个邻接顶点 */
int GetFirstNeighbor(const GraphLink& g, T vertex);
/* v的某一个邻接顶点的是w，取w后一个顶点 */
int GetNextNeighbor(const GraphLink& g, T v, T w);

/* 深度优先遍历 */
void DFS(const GraphLink& g, T vertex);
/* 广度优先遍历 */
void BFS(const GraphLink& g, T vertex);
/* 非连通图深度优先遍历 */
void Components(GraphLink& g);
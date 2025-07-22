#pragma once

typedef char T;
#define DEFAULT_VERTEX_SIZE  20

struct Edge {
	int dest;   //�����±�
	Edge* link; //����
};
struct Vertex {
	T data;
	Edge* adj;  //����͵�һ����
};
struct GraphLink {
	int MaxVertices;  //��󶥵���
	int NumVertices;  //��ǰ������
	int NumEdges;     //����
	Vertex* NodeTable;  //�����б�
};

void InitGraph(GraphLink& g);
void DestroryGraph(GraphLink& g);

void InsertVertex(GraphLink& g, T v);
int GetVertexPos(const GraphLink& g, T v);
void InsertEdge(GraphLink& g, T v1, T v2);
void RemoveEdge(GraphLink& g, T v1, T v2);
void RemoveVertex(GraphLink& g, T vertex);
void ShowGraph(const GraphLink& g);

/* ȡ��һ���ڽӶ��� */
int GetFirstNeighbor(const GraphLink& g, T vertex);
/* v��ĳһ���ڽӶ������w��ȡw��һ������ */
int GetNextNeighbor(const GraphLink& g, T v, T w);

/* ������ȱ��� */
void DFS(const GraphLink& g, T vertex);
/* ������ȱ��� */
void BFS(const GraphLink& g, T vertex);
/* ����ͨͼ������ȱ��� */
void Components(GraphLink& g);
#pragma once

typedef char T;
#define DEFAULT_VERTEX_SIZE  20

struct GraphMtx {
	int MaxVertices;  //��󶥵���
	int NumVertices;  //��ǰ������
	int NumEdges;     //����

	T* VerticesList;  //��������
	int** Edge;       //��ֵ����
};

void InitGraph(GraphMtx& g);
void DestroyGraph(GraphMtx& g);

void InsertVertex(GraphMtx& g, T v);
int GetVertexPos(const GraphMtx& g, T v);
void InsertEdge(GraphMtx& g, T v1, T v2);
void RemoveEdge(GraphMtx& g, T v1, T v2);
void RemoveVertex(GraphMtx& g, T v);
void ShowGraph(const GraphMtx& g);

/* ȡ��һ���ڽӶ��� */
int GetFirstNeighbor(const GraphMtx& g, T v);
/* v��ĳһ���ڽӶ������w��ȡw��һ������ */
int GetNextNeighbor(const GraphMtx& g, T v, T w);
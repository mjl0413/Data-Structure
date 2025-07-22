#include <iostream>
#include "GraphMatrix.h"
using namespace std;

void InitGraph(GraphMtx& g)
{
	g.MaxVertices = DEFAULT_VERTEX_SIZE;
	g.NumVertices = 0;
	g.NumEdges = 0;

	g.VerticesList = new(nothrow) T[g.MaxVertices];
	g.Edge = new(nothrow) int* [g.MaxVertices];
	if (g.VerticesList == nullptr || g.Edge == nullptr)
		exit(-1);
	for (int i = 0; i < g.MaxVertices; i++) {
		g.Edge[i] = new(nothrow) int[g.MaxVertices];
		if (g.Edge[i] == nullptr)
			exit(-1);
		for (int j = 0; j < g.MaxVertices; j++)
			g.Edge[i][j] = 0;
	}
}
void DestroyGraph(GraphMtx& g)
{
	delete[] g.VerticesList;
	for (int i = 0; i < g.MaxVertices; i++)
		delete[] g.Edge[i];
	delete[] g.Edge;

	g.MaxVertices = g.NumVertices = g.NumEdges = 0;
}

void InsertVertex(GraphMtx& g, T v)
{
	if (g.NumEdges >= g.MaxVertices)
		return;
	g.VerticesList[g.NumVertices++] = v;
}
int GetVertexPos(const GraphMtx& g, T v)
{
	for (int i = 0; i < g.NumVertices; i++) 
		if (g.VerticesList[i] == v)
			return i;
	return -1;
}
void InsertEdge(GraphMtx& g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	//无向图
	g.Edge[p1][p2] = g.Edge[p2][p1] = 1;
	g.NumEdges++;
}
void RemoveEdge(GraphMtx& g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	//无向图
	if (g.Edge[p1][p2] == 1) {
		g.Edge[p1][p2] = g.Edge[p2][p1] = 0;
		g.NumEdges--;
	}
}
void RemoveVertex(GraphMtx& g, T v)
{
	int p = GetVertexPos(g, v);
	if (p == -1)
		return;

	//从顶点列表中删除
	for (int k = p; k < g.NumVertices - 1; k++)
		g.VerticesList[k] = g.VerticesList[k + 1];
	int nums = 0;
	for (int i = 0; i < g.NumVertices; i++) 
		if (g.Edge[p][i] != 0)
			nums++;

	//删除关联边（矩阵该行）
	for (int i = p; i < g.NumVertices - 1; i++)
		for (int j = 0; j < g.NumVertices; j++)
			g.Edge[i][j] = g.Edge[i + 1][j];
	//删除关联边（矩阵该列）
	for (int i = p; i < g.NumVertices - 1; i++)
		for (int j = 0; j < g.NumVertices; j++)
			g.Edge[j][i] = g.Edge[j][i + 1];

	g.NumVertices--;
	g.NumEdges -= nums;
}
void ShowGraph(const GraphMtx& g)
{
	cout << "   ";
	for (int k = 0; k < g.NumVertices; k++)
		cout << g.VerticesList[k] << "  ";
	cout << endl;

	for (int i = 0; i < g.NumVertices; i++) {
		cout << g.VerticesList[i] << "  ";
		for (int j = 0; j < g.NumVertices; j++)
			cout << g.Edge[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

int GetFirstNeighbor(const GraphMtx& g, T v)
{
	int p = GetVertexPos(g, v);
	if (p == -1)
		return -1;

	for (int i = 0; i < g.NumVertices; i++)
		if (g.Edge[p][i] == 1)
			return i;
	return -1;
}
int GetNextNeighbor(const GraphMtx& g, T v, T w)
{
	int pv = GetVertexPos(g, v);
	int pw = GetVertexPos(g, w);
	if (pv == -1 || pw == -1)
		return -1;

	for (int i = pw + 1; i < g.NumVertices; i++)
		if (g.Edge[pv][i] == 1)
			return i;
	return -1;
}
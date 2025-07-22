#include <iostream>
#include "CriticalPath.h"
using namespace std;

void C_InsertEdge(GraphMtx& g, T v1, T v2, E cost)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	//有向带权图
	g.Edge[p1][p2] = cost;
	g.NumEdges++;
}
int C_GetFirstNeighbor(const GraphMtx& g, T v)
{
	int p = GetVertexPos(g, v);
	if (p == -1)
		return -1;

	for (int i = 0; i < g.NumVertices; i++)
		if (g.Edge[p][i] != 0)
			return i;
	return -1;
}
int C_GetNextNeighbor(const GraphMtx& g, T v, T w)
{
	int pv = GetVertexPos(g, v);
	int pw = GetVertexPos(g, w);
	if (pv == -1 || pw == -1)
		return -1;

	for (int i = pw + 1; i < g.NumVertices; i++)
		if (g.Edge[pv][i] != 0)
			return i;
	return -1;
}

static E GetWeight(const GraphMtx& g, const int v1, const int v2)
{
	if (v1 == -1 || v2 == -1)
		return INT_MAX;
	return g.Edge[v1][v2];
}
void CriticalPath(const GraphMtx& g)
{
	int n = g.NumVertices;
	//最早开始时间
	int* ve = new(nothrow) int[n];
	//最晚开始时间
	int* vl = new(nothrow) int[n];
	if (ve == nullptr || vl == nullptr)
		exit(-1);
	for (int i = 0; i < n; i++)
		ve[i] = 0, vl[i] = INT_MAX;

	//正向求最早开始时间
	for (int i = 0; i < n; i++)
	{
		int j = C_GetFirstNeighbor(g, g.VerticesList[i]);
		while (j != -1) {
			int w = GetWeight(g, i, j);
			if (ve[i] + w > ve[j])
				ve[j] = ve[i] + w;
			j = C_GetNextNeighbor(g, g.VerticesList[i], g.VerticesList[j]);
		}
	}
	//反向求最晚开始时间
	vl[n - 1] = ve[n - 1];
	for (int i = n - 2; i > 0; i--)
	{
		int j = C_GetFirstNeighbor(g, g.VerticesList[i]);
		while (j != -1) {
			int w = GetWeight(g, i, j);
			if (vl[j] - w < vl[i])
				vl[i] = vl[j] - w;
			j = C_GetNextNeighbor(g, g.VerticesList[i], g.VerticesList[j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int j = C_GetFirstNeighbor(g, g.VerticesList[i]);
		while (j != -1) {
			int early = ve[i];
			int last = vl[j] - GetWeight(g, i, j);
			if (early == last)
				cout << "<" << g.VerticesList[i] << ", "
				<< g.VerticesList[j] << ">" << endl;
			j = C_GetNextNeighbor(g, g.VerticesList[i], g.VerticesList[j]);
		}
	}
	delete[] ve;
	delete[] vl;
}
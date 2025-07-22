#include <iostream>
#include "MinTree.h"
using namespace std;

void P_InitGraph(GraphMtx& g)
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
		for (int j = 0; j < g.MaxVertices; j++) {
			if (i == j)
				g.Edge[i][j] = 0;
			else
				g.Edge[i][j] = INT_MAX;
		}
	}
}
void InsertEdge(GraphMtx& g, T v1, T v2, E cost)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	//无向带权图
	g.Edge[p1][p2] = g.Edge[p2][p1] = cost;
	g.NumEdges++;
}
void P_ShowGraph(const GraphMtx& g)
{
	cout << "   ";
	for (int k = 0; k < g.NumVertices; k++)
		cout << g.VerticesList[k] << "  ";
	cout << endl;

	for (int i = 0; i < g.NumVertices; i++) {
		cout << g.VerticesList[i] << "  ";
		for (int j = 0; j < g.NumVertices; j++) {
			if (g.Edge[i][j] != INT_MAX)
				cout << g.Edge[i][j] << "  ";
			else
				cout << "@" << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

static E GetWeight(const GraphMtx& g, const int v1, const int v2)
{
	if (v1 == -1 || v2 == -1)
		return INT_MAX;
	return g.Edge[v1][v2];
}
void Prim(const GraphMtx& g, T vertex)
{
	int n = g.NumVertices;
	E* lowcost = new(nothrow) E[n]; //到该顶点的最低花费（边权）
	int* mst = new(nothrow) int[n]; //到该顶点最低花费边的起始点
	if (lowcost == nullptr || mst == nullptr)
		exit(-1);

	int k = GetVertexPos(g, vertex);
	for (int i = 0; i < n; i++) {
		if (i == k)
			lowcost[i] = 0;
		else {
			lowcost[i] = GetWeight(g, k, i);
			mst[i] = k;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		//当前最小值与对应的下标
		int min = INT_MAX, min_index = -1;
		for (int j = 0; j < n; j++) {
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];
				min_index = j;
			}
		}

		int begin = mst[min_index];
		int end = min_index;
		cout << g.VerticesList[begin] << "-->" << g.VerticesList[end]
			<< " : " << min << endl;
		lowcost[min_index] = 0;

		for (int k = 0; k < n; k++) {
			int cost = GetWeight(g, min_index, k);
			if (cost < lowcost[k]) {
				lowcost[k] = cost;
				mst[k] = min_index;
			}
		}
	}
}

//判断两个顶点是否在同一个联通分支里
static bool SameParent(int* parent, int src, int dst)
{
	while (parent[src] != src)
		src = parent[src];
	while (parent[dst] != dst)
		dst = parent[dst];
	return src == dst;
}
//标记parent数组，更新联通分支即加入新边
static void SameMark(int* parent, int src, int dst)
{
	while (parent[src] != src)
		src = parent[src];
	while (parent[dst] != dst)
		dst = parent[dst];
	parent[dst] = src;
}
void Kruskal(const GraphMtx& g)
{
	int n = g.NumVertices;
	K_Edge* edge = new(nothrow) K_Edge[n * (n - 1) / 2];
	if (edge == nullptr)
		exit(-1);

	int k = 0;  //查找上三角，k为边数
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (g.Edge[i][j] != 0 && g.Edge[i][j] != INT_MAX) {
				edge[k].x = i;
				edge[k].y = j;
				edge[k].cost = g.Edge[i][j];
				k++;
			}
	for (int i = 1; i < k; i++)
		for (int j = 0; j < k - i; j++)
			if (edge[j].cost > edge[j + 1].cost)
				swap(edge[j], edge[j + 1]);

	//记录每个联通子图
	int* parent = new(nothrow) int[n];
	if (parent == nullptr)
		exit(-1);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	
	for (int i = 0; i < n; i++) {
		if (!SameParent(parent, edge[i].x, edge[i].y)) {
			cout << g.VerticesList[edge[i].x] << "-->" << g.VerticesList[edge[i].y]
				<< " : " << edge[i].cost << endl;
			SameMark(parent, edge[i].x, edge[i].y);
		}
	}
}
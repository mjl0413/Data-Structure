#pragma once

#include "GraphMatrix.h"

static E GetWeight(const GraphMtx& g, const int v1, const int v2)
{
	if (v1 == -1 || v2 == -1)
		return INT_MAX;
	return g.Edge[v1][v2];
}
void ShortestPath(const GraphMtx& g, T vertex, E dist[], int path[])
{
	int n = g.NumVertices;
	//记录顶点是否已加入路径
	bool* S = new(nothrow) bool[n];
	if (S == nullptr)
		exit(-1);

	//初始化
	int v = GetVertexPos(g, vertex);
	for (int i = 0; i < n; i++)
	{
		dist[i] = GetWeight(g, v, i);
		S[i] = false;
		if (i != v && dist[i] < INT_MAX)
			path[i] = v;
		else
			path[i] = -1;
	}

	S[v] = true;
	for (int i = 0; i < n - 1; i++)
	{
		int min = INT_MAX, u = v;
		//选择
		for (int j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		
		//更新
		S[u] = true;
		for (int k = 0; k < n; k++) {
			int w = GetWeight(g, u, k);
			if (S[k] == false && w < INT_MAX && dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}
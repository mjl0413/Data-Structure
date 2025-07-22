#pragma once

#include "GraphMatrix.h"
typedef int E;

void P_InitGraph(GraphMtx& g);
void InsertEdge(GraphMtx& g, T v1, T v2, E cost);
void P_ShowGraph(const GraphMtx& g);

void Prim(const GraphMtx& g, T vertex);

struct K_Edge {
	int x;  //边起始点
	int y;  //边终止点
	E cost; //权值
};
void Kruskal(const GraphMtx& g);
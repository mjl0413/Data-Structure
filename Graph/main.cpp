#include <iostream>
using namespace std;

#include "GraphMatrix.h"
#include "GraphLink.h"
#include "MinTree.h"
#include "TopologicalSort.hpp"
#include "CriticalPath.h"
#include "ShortestPath.hpp"

#define MATRIX    0
#define LINK      0
#define TRAVERSE  0
#define MINTREE   0
#define TOPO      0
#define CRITICAL  0
#define SHORTEST  1

int main()
{
#if MATRIX
	GraphMtx gm;
	InitGraph(gm);

	for (int i = 0; i < 5; i++)
		InsertVertex(gm, 'A' + i);
	InsertEdge(gm, 'A', 'B');
	InsertEdge(gm, 'A', 'D');
	InsertEdge(gm, 'B', 'C');
	InsertEdge(gm, 'B', 'E');
	InsertEdge(gm, 'C', 'D');
	InsertEdge(gm, 'C', 'E');
	ShowGraph(gm);

	RemoveEdge(gm, 'B', 'C');
	ShowGraph(gm);
	RemoveVertex(gm, 'C');
	ShowGraph(gm);

	DestroyGraph(gm);

#elif LINK
	GraphLink gl;
	InitGraph(gl);

	for (int i = 0; i < 5; i++)
		InsertVertex(gl, 'A' + i);
	InsertEdge(gl, 'A', 'B');
	InsertEdge(gl, 'A', 'D');
	InsertEdge(gl, 'B', 'C');
	InsertEdge(gl, 'B', 'E');
	InsertEdge(gl, 'C', 'D');
	InsertEdge(gl, 'C', 'E');
	ShowGraph(gl);

	RemoveEdge(gl, 'B', 'C');
	ShowGraph(gl);
	RemoveVertex(gl, 'C');
	ShowGraph(gl);

	DestroryGraph(gl);

#elif TRAVERSE
	GraphLink gl;
	InitGraph(gl);

	for (int i = 0; i < 8; i++)
		InsertVertex(gl, 'A' + i);
	InsertEdge(gl, 'A', 'B');
	InsertEdge(gl, 'A', 'C');
	InsertEdge(gl, 'B', 'D');
	InsertEdge(gl, 'B', 'E');
	InsertEdge(gl, 'C', 'F');
	InsertEdge(gl, 'C', 'G');
	InsertEdge(gl, 'D', 'H');
	InsertEdge(gl, 'E', 'H');
	InsertEdge(gl, 'F', 'G');
	ShowGraph(gl);

	DFS(gl, 'A');
	BFS(gl, 'A');

	DestroryGraph(gl);
	cout << endl;

	InitGraph(gl);
	for (int i = 0; i < 13; i++)
		InsertVertex(gl, 'A' + i);
	InsertEdge(gl, 'A', 'B');
	InsertEdge(gl, 'A', 'C');
	InsertEdge(gl, 'A', 'F');
	InsertEdge(gl, 'A', 'L');
	InsertEdge(gl, 'B', 'M');
	InsertEdge(gl, 'L', 'J');
	InsertEdge(gl, 'L', 'M');
	InsertEdge(gl, 'J', 'M');
	InsertEdge(gl, 'D', 'E');
	InsertEdge(gl, 'G', 'H');
	InsertEdge(gl, 'G', 'I');
	InsertEdge(gl, 'G', 'K');
	InsertEdge(gl, 'H', 'K');
	ShowGraph(gl);

	Components(gl);

	DestroryGraph(gl);

#elif MINTREE
	GraphMtx gm;
	P_InitGraph(gm);

	for (int i = 0; i < 6; i++)
		InsertVertex(gm, 'A' + i);
	InsertEdge(gm, 'A', 'B', 6);
	InsertEdge(gm, 'A', 'C', 1);
	InsertEdge(gm, 'A', 'D', 5);
	InsertEdge(gm, 'B', 'C', 5);
	InsertEdge(gm, 'C', 'D', 5);
	InsertEdge(gm, 'B', 'E', 3);
	InsertEdge(gm, 'C', 'E', 6);
	InsertEdge(gm, 'C', 'F', 4);
	InsertEdge(gm, 'D', 'F', 2);
	InsertEdge(gm, 'E', 'F', 6);
	P_ShowGraph(gm);

	Prim(gm, 'A');
	cout << endl;
	Kruskal(gm);

	DestroyGraph(gm);
	
#elif TOPO
	GraphLink gl;
	InitGraph(gl);

	for (int i = 0; i < 6; i++)
		InsertVertex(gl, 'A' + i);
	P_InsertEdge(gl, 'A', 'B');
	P_InsertEdge(gl, 'A', 'C');
	P_InsertEdge(gl, 'A', 'D');
	P_InsertEdge(gl, 'C', 'B');
	P_InsertEdge(gl, 'C', 'E');
	P_InsertEdge(gl, 'D', 'E');
	P_InsertEdge(gl, 'F', 'D');
	P_InsertEdge(gl, 'F', 'E');
	ShowGraph(gl);

	TopologicalSort(gl);

	DestroryGraph(gl);

#elif CRITICAL
	GraphMtx gm;
	InitGraph(gm);

	for (int i = 0; i < 9; i++)
		InsertVertex(gm, 'A' + i);
	C_InsertEdge(gm, 'A', 'B', 6);
	C_InsertEdge(gm, 'A', 'C', 4);
	C_InsertEdge(gm, 'A', 'D', 5);
	C_InsertEdge(gm, 'B', 'E', 1);
	C_InsertEdge(gm, 'C', 'E', 1);
	C_InsertEdge(gm, 'D', 'F', 2);
	C_InsertEdge(gm, 'E', 'G', 9);
	C_InsertEdge(gm, 'E', 'H', 7);
	C_InsertEdge(gm, 'F', 'H', 4);
	C_InsertEdge(gm, 'G', 'I', 2);
	C_InsertEdge(gm, 'H', 'I', 6);
	ShowGraph(gm);

	CriticalPath(gm);

	DestroyGraph(gm);

#elif SHORTEST
	GraphMtx gm;
	P_InitGraph(gm);

	for (int i = 0; i < 5; i++)
		InsertVertex(gm, 'A' + i);
	C_InsertEdge(gm, 'A', 'B', 1);
	C_InsertEdge(gm, 'A', 'D', 3);
	C_InsertEdge(gm, 'A', 'E', 10);
	C_InsertEdge(gm, 'B', 'C', 5);
	C_InsertEdge(gm, 'C', 'E', 1);
	C_InsertEdge(gm, 'D', 'C', 2);
	C_InsertEdge(gm, 'D', 'E', 6);
	P_ShowGraph(gm);

	int n = gm.NumVertices;
	//起始点到该顶点的最短距离
	E* dist = new(nothrow) E[n];
	//最短路径上该顶点的上一个点
	int* path = new(nothrow) int[n];
	if (dist == nullptr || path == nullptr)
		exit(-1);
	ShortestPath(gm, 'A', dist, path);

	delete[] dist;
	delete[] path;
	DestroyGraph(gm);
#endif
	return 0;
}
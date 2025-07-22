#include <iostream>
#include "Queue.h"
#include "GraphLink.h"
using namespace std;

void InitGraph(GraphLink& g)
{
	g.MaxVertices = DEFAULT_VERTEX_SIZE;
	g.NumVertices = 0;
	g.NumEdges = 0;

	g.NodeTable = new(nothrow) Vertex[g.MaxVertices];
	if (g.NodeTable == nullptr)
		exit(-1);
	for (int i = 0; i < g.MaxVertices; i++)
		g.NodeTable[i].adj = nullptr;
}
void DestroryGraph(GraphLink& g)
{
	Edge* p;
	for (int i = 0; i < g.NumVertices; i++) {
		p = g.NodeTable[i].adj;
		while (p != nullptr) {
			g.NodeTable[i].adj = p->link;
			delete p;
			p = g.NodeTable[i].adj;
		}
	}
	delete[] g.NodeTable;
	g.MaxVertices = g.NumVertices = g.NumEdges = 0;
}

void InsertVertex(GraphLink& g, T v)
{
	if (g.NumVertices >= g.MaxVertices)
		return;
	g.NodeTable[g.NumVertices++].data = v;
}
int GetVertexPos(const GraphLink& g, T v)
{
	for (int i = 0; i < g.NumVertices; i++)
		if (g.NodeTable[i].data == v)
			return i;
	return -1;
}
void InsertEdge(GraphLink& g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	Edge* s;
	//v1-->v2
	s = new(nothrow) Edge;
	if (s == nullptr)
		exit(-1);
	s->dest = p2;
	s->link = g.NodeTable[p1].adj;
	g.NodeTable[p1].adj = s;

	//v2-->v1
	s = new(nothrow) Edge;
	if (s == nullptr)
		exit(-1);
	s->dest = p1;
	s->link = g.NodeTable[p2].adj;
	g.NodeTable[p2].adj = s;

	g.NumEdges++;
}
void RemoveEdge(GraphLink& g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	Edge* p = nullptr, * q = nullptr; //q指向p的前驱
	//删除v1-->v2
	p = g.NodeTable[p1].adj;
	while (p != nullptr && p->dest != p2) {
		q = p;
		p = p->link;
	}
	if (p == nullptr)
		return;
	if (q == nullptr)
		g.NodeTable[p1].adj = p->link;
	else
		q->link = p->link;
	delete p;
	
	//删除v2-->v1
	p = g.NodeTable[p2].adj;
	while (p != nullptr && p->dest != p1) {
		q = p;
		p = p->link;
	}
	if (p == nullptr)
		return;
	if (q == nullptr)
		g.NodeTable[p2].adj = p->link;
	else
		q->link = p->link;
	delete p;
}
void RemoveVertex(GraphLink& g, T vertex)
{
	int v = GetVertexPos(g, vertex);
	if (v == -1)
		return;

	Edge* p = g.NodeTable[v].adj;

	//先删除边再删顶点
	Edge* q = nullptr;
	while (p != nullptr) 
	{
		int k = p->dest;
		Edge* s = g.NodeTable[k].adj;
		while (s != nullptr && s->dest != v) {
			q = s;
			s = s->link;
		}
		if (s != nullptr) {
			if (q == nullptr)
				g.NodeTable[k].adj = s->link;
			else
				q->link = s->link;
			delete s;
		}

		g.NodeTable[v].adj = p->link;
		delete p;
		p = g.NodeTable[v].adj;
	}
	g.NumVertices--;

	g.NodeTable[v].data = g.NodeTable[g.NumVertices].data;
	g.NodeTable[v].adj = g.NodeTable[g.NumVertices].adj;
	p = g.NodeTable[v].adj;
	while (p != nullptr) 
	{
		int k = p->dest;
		Edge* s = g.NodeTable[k].adj;
		while (s != nullptr) {
			if (s->dest == g.NumVertices) {
				s->dest = v;
				break;
			}
			s = s->link;
		}
		p = p->link;
	}
}
void ShowGraph(const GraphLink& g)
{
	for (int i = 0; i < g.NumVertices; i++) {
		cout << i << ": " << g.NodeTable[i].data << "-->";
		Edge* p = g.NodeTable[i].adj;
		while (p != nullptr) {
			cout << p->dest << "-->";
			p = p->link;
		}
		cout << "NULL" << endl;
	}
	cout << endl;
}

int GetFirstNeighbor(const GraphLink& g, T vertex)
{
	int v = GetVertexPos(g, vertex);
	if (v == -1)
		return -1;
	Edge* p = g.NodeTable[v].adj;
	if (p == nullptr)
		return -1;
	return p->dest;
}
int GetNextNeighbor(const GraphLink& g, T v, T w)
{
	int pv = GetVertexPos(g, v);
	int pw = GetVertexPos(g, w);
	if (pv == -1 || pw == -1)
		return -1;

	Edge* p = g.NodeTable[pv].adj;
	while (p != nullptr && p->dest != pw)
		p = p->link;
	if (p != nullptr && p->link != nullptr)
		return p->link->dest;
	return -1;
}

static void DFS(const GraphLink& g, int v, bool visited[])
{
	cout << g.NodeTable[v].data << " ";
	visited[v] = true;

	int w = GetFirstNeighbor(g, g.NodeTable[v].data);
	while (w != -1) {
		if (!visited[w])
			DFS(g, w, visited);
		w = GetNextNeighbor(g, g.NodeTable[v].data, g.NodeTable[w].data);
	}
}
void DFS(const GraphLink& g, T vertex)
{
	int n = g.NumVertices;
	bool* visit = new(nothrow) bool[n];
	if (visit == nullptr)
		return;
	for (int i = 0; i < n; i++)
		visit[i] = false;

	int v = GetVertexPos(g, vertex);
	if (v != -1)
		DFS(g, v, visit);
	cout << endl;
	delete[] visit;
}
void BFS(const GraphLink& g, T vertex)
{
	int n = g.NumVertices;
	bool* visit = new(nothrow) bool[n];
	if (visit == nullptr)
		return;
	for (int i = 0; i < n; i++)
		visit[i] = false;
	LinkQueue Q;
	InitQueue(Q);

	cout << vertex << " ";
	int v = GetVertexPos(g, vertex);
	if (v == -1)
		return;
	visit[v] = true;
	EnQueue(Q, v);
	while (!IsEmpty(Q))
	{
		GetHead(Q, v);
		DeQueue(Q);

		int w = GetFirstNeighbor(g, g.NodeTable[v].data);
		while (w != -1) {
			if (!visit[w]) {
				cout << g.NodeTable[w].data << " ";
				visit[w] = true;
				EnQueue(Q, w);
			}
			w = GetNextNeighbor(g, g.NodeTable[v].data, g.NodeTable[w].data);
		}
	}
	cout << endl;

	delete[] visit;
	DestroyQueue(Q);
}
void Components(GraphLink& g)
{
	int n = g.NumVertices;
	bool* visit = new(nothrow) bool[n];
	if (visit == nullptr)
		return;
	for (int i = 0; i < n; i++)
		visit[i] = false;

	for (int i = 0; i < n; i++)
		if (!visit[i])
			DFS(g, i, visit);
	cout << endl;
	delete[] visit;
}
#pragma once

#include <iostream>
#include "GraphLink.h"
using namespace std;

void P_InsertEdge(GraphLink& g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);
	if (p1 == -1 || p2 == -1)
		return;

	Edge* s;
	s = new(nothrow) Edge;
	if (s == nullptr)
		exit(-1);
	s->dest = p2;
	s->link = g.NodeTable[p1].adj;
	g.NodeTable[p1].adj = s;

	g.NumEdges++;
}

void TopologicalSort(const GraphLink& g)
{
	int n = g.NumVertices;
	//�������
	int* count = new(nothrow) int[n];
	if (count == nullptr)
		exit(-1);
	for (int i = 0; i < n; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++) {
		Edge* p = g.NodeTable[i].adj;
		while (p != nullptr) {
			count[p->dest]++;
			p = p->link;
		}
	}

	int top = -1;  //ģ��ջ�ṹ
	//ģ����ջ
	for (int i = 0; i < n; i++) 
		if (count[i] == 0) {
			count[i] = top;
			top = i;
		}
	
	for (int i = 0; i < n; i++)
	{
		if (top == -1) {
			cout << "�������л�·" << endl;
			return;
		}
		//ģ���ջ
		int v = top;
		top = count[top];
		cout << g.NodeTable[v].data << " ";

		int w = GetFirstNeighbor(g, g.NodeTable[v].data);
		while (w != -1) {
			if (--count[w] == 0) {
				count[w] = top;
				top = w;
			}
			w = GetNextNeighbor(g, g.NodeTable[v].data, g.NodeTable[w].data);
		}
	}
	cout << endl;
	delete[] count;
}
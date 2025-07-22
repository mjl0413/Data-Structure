#pragma once

#include <iostream>
#include "GraphMatrix.h"
using namespace std;

typedef int E;

void C_InsertEdge(GraphMtx& g, T v1, T v2, E cost);
int C_GetFirstNeighbor(const GraphMtx& g, T v);
int C_GetNextNeighbor(const GraphMtx& g, T v, T w);

void CriticalPath(const GraphMtx& g);
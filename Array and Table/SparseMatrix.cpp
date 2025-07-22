#include <iostream>
#include <fstream>
#include "SparseMatrix.h"
using namespace std;

void CreateMatrix(SMatrix& M)
{
	ifstream file;
	file.open("Matrix.txt", ios::in | ios::binary);
	if (file.is_open() == false)
		exit(-1);

	file >> M.mu >> M.nu;
	int value, k = 0;
	for (int i = 0; i < M.mu; i++)
		for (int j = 0; j < M.nu; j++) {
			file >> value;
			if (value != 0) {
				M.data[k].i = i;
				M.data[k].j = j;
				M.data[k].e = value;
				k++;
			}
		}
	M.tu = k;

	file.close();
}
void PrintMatrix(const SMatrix& M)
{
	cout << "row=" << M.mu << ", col=" << M.nu << endl;
	for (int i = 0; i < M.tu; i++)
		cout << "(" << M.data[i].i << ", " << M.data[i].j << ", " << M.data[i].e << ")" << endl;
}

void CopyMatrix(SMatrix& M, SMatrix& T)
{
	T.mu = M.mu, T.nu = M.nu, T.tu = M.tu;
	for (int i = 0; i < M.tu; i++)
		T.data[i] = M.data[i];
}
void TransposeMatrix(const SMatrix& M, SMatrix& T)
{
	T.mu = M.nu, T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu == 0)
		return;

	int k = 0;
	for (int col = 0; col < M.nu; col++)
		for (int h = 0; h < M.tu; h++)
			if (M.data[h].j == col)
			{
				T.data[k].i = M.data[h].j;
				T.data[k].j = M.data[h].i;
				T.data[k].e = M.data[h].e;
				k++;
			}
		
}
void FastTransposeMatrix(const SMatrix& M, SMatrix& T)
{
	T.mu = M.nu, T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu == 0)
		return;
	//M矩阵每一列非零元的个数
	int* num = new(nothrow) int[M.nu];
	if (num == nullptr)
		exit(-1);
	for (int col = 0; col < M.nu; col++)
		num[col] = 0;
	//M矩阵每列首个非零元压缩存储的位置
	int* cpot = new(nothrow) int[M.nu];
	if (cpot == nullptr) {
		delete[] num;
		exit(-1);
	}

	for (int t = 0; t < M.tu; t++)
		num[M.data[t].j]++;
	cpot[0] = 0;
	for (int col = 1; col < M.nu; col++)
		cpot[col] = cpot[col - 1] + num[col - 1];
	
	int h = 0;
	for (int k = 0; k < M.tu; k++) {
		int col = M.data[k].j;
		h = cpot[col];
		T.data[h].i = M.data[k].j;
		T.data[h].j = M.data[k].i;
		T.data[h].e = M.data[k].e;
		cpot[col]++;
	}

	delete[] num;
	delete[] cpot;
}
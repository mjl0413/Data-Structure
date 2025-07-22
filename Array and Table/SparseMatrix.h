#pragma once

typedef int ElemType;

#define MAXSIZE  100  //最大非零元个数
struct Triple {
	int i;
	int j;
	ElemType e;
};
struct SMatrix {
	Triple data[MAXSIZE];
	int mu;  //行数
	int nu;  //列数
	int tu;  //非零元数
};

void CreateMatrix(SMatrix& M);
void PrintMatrix(const SMatrix& M);

/* 将M矩阵拷贝到T矩阵 */
void CopyMatrix(SMatrix& M, SMatrix& T);
/*
//矩阵加法
void AddMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
//矩阵减法
void SubMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
//矩阵乘法
void MulMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
*/
/* 矩阵转置 */
void TransposeMatrix(const SMatrix& M, SMatrix& T);
void FastTransposeMatrix(const SMatrix& M, SMatrix& T);
#pragma once

typedef int ElemType;

#define MAXSIZE  100  //������Ԫ����
struct Triple {
	int i;
	int j;
	ElemType e;
};
struct SMatrix {
	Triple data[MAXSIZE];
	int mu;  //����
	int nu;  //����
	int tu;  //����Ԫ��
};

void CreateMatrix(SMatrix& M);
void PrintMatrix(const SMatrix& M);

/* ��M���󿽱���T���� */
void CopyMatrix(SMatrix& M, SMatrix& T);
/*
//����ӷ�
void AddMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
//�������
void SubMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
//����˷�
void MulMatrix(const SMatrix& M, const SMatrix& N, SMatrix& T);
*/
/* ����ת�� */
void TransposeMatrix(const SMatrix& M, SMatrix& T);
void FastTransposeMatrix(const SMatrix& M, SMatrix& T);
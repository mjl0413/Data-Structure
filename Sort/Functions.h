#pragma once

typedef int T;

#define MAXSIZE  20
typedef T SqList[MAXSIZE];

/* ֱ�Ӳ������� */
void InsertSort(SqList& L, int n);
/* �۰�������� */
void BInsertSort(SqList& L, int n);
/* 2-·�������� */
void TWayInsertSort(SqList& L, int n);

/* ��̬���� */
struct SLNode {
	T data;
	int link;
};
typedef SLNode Table[MAXSIZE];
/* ��������� */
void TableInsertSort(Table& L, int n);

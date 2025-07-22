#pragma once

typedef int T;

#define MAXSIZE  20
typedef T SqList[MAXSIZE];

/* ÷±Ω”≤Â»Î≈≈–Ú */
void InsertSort(SqList& L, int n);
/* ’€∞Î≤Â»Î≈≈–Ú */
void BInsertSort(SqList& L, int n);
/* 2-¬∑≤Â»Î≈≈–Ú */
void TWayInsertSort(SqList& L, int n);

/* æ≤Ã¨¡¥±Ì */
struct SLNode {
	T data;
	int link;
};
typedef SLNode Table[MAXSIZE];
/* ±Ì≤Â»Î≈≈–Ú */
void TableInsertSort(Table& L, int n);

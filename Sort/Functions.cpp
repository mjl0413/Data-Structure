#include <iostream>
#include "Functions.h"
using namespace std;

/* 效率低，思路简单的方法
void InsertSort(SqList& L, int n)
{
	for (int i = 1; i < n; i++) 
		if (L[i] < L[i - 1]) {
			swap(L[i], L[i - 1]);
			for (int j = i - 1; j > 0 && L[j] < L[j - 1]; j--)
				swap(L[j], L[j - 1]);
		}
}*/

void InsertSort(SqList& L, int n)
{
	for (int i = 2; i < n; i++)
		if (L[i] < L[i - 1]) {
			L[0] = L[i];
			L[i] = L[i - 1];

			int j;
			for (j = i - 2; j > 0 && L[0] < L[j]; j--)
				L[j + 1] = L[j];
			L[j + 1] = L[0];
		}
}
void BInsertSort(SqList& L, int n)
{
	for (int i = 2; i < n; i++) {
		L[0] = L[i];
		int low = 1, high = i - 1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (L[0] >= L[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		for (int j = i; j > high + 1; j--)
			L[j] = L[j - 1];
		L[high + 1] = L[0];
	}
}
void TWayInsertSort(SqList& L, int n)
{
	SqList temp = { 0 };
	temp[0] = L[0];
	int head = 0, tail = 0;

	for (int i = 1; i < n; i++) {
		if (L[i] < temp[head]) {
			head = (head - 1 + n) % n;
			temp[head] = L[i];
		}
		else if (L[i] > temp[tail]) {
			tail++;
			temp[tail] = L[i];
		}
		else {
			tail++;
			temp[tail] = temp[tail - 1];
			int j;
			for (j = tail - 1; L[i] < temp[(j - 1 + n) % n]; j = (j - 1 + n) % n) {
				temp[j] = temp[(j - 1 + n) % n];
			}
			temp[j] = L[i];
		}
	}

	for (int i = 0; i < n; i++) {
		L[i] = temp[head];
		head = (head + 1) % n;
	}
}
void TableInsertSort(Table& L, int n)
{

}
#include <iostream>
#include "Functions.h"
using namespace std;

#define USE_ZERO_SPACE
#define MOVE_INSERT   0
#define TABLE_INSERT  1

int main()
{
#ifdef USE_ZERO_SPACE
	//0用来占位置，监视器
	SqList L = { 0,49,38,65,97,76,13,27,49 };
	int n = 9;
#if MOVE_INSERT
	InsertSort(L, n);
	BInsertSort(L, n);
#elif TABLE_INSERT
	Table tb = { 0 };
	tb[0].data = INT_MAX;
	tb[0].link = 0;
	for (int i = 1; i < n; i++) {
		tb[i].data = L[i];
		tb[i].link = 0;
	}

#endif
#else
	SqList L = { 49,38,65,97,76,13,27,49 };
	int n = 8;
	TWayInsertSort(L, n);

#endif

#ifdef USE_ZERO_SPACE
	for (int i = 1; i < n; i++)
		cout << L[i] << " ";
	cout << endl; 
#else
	for (int i = 0; i < n; i++)
		cout << L[i] << " ";
	cout << endl;
#endif

	return 0;
}
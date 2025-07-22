#include <iostream>
#include "StaticList.h"
using namespace std;

int new_SL(StaticList& space)
{
	int i = space[1].cur;
	if (i != 0)
		space[1].cur = space[i].cur;
	return i;
}
void delete_SL(StaticList& space, int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
}

void InitSList(StaticList& space)
{
	for (int i = 1; i < MAX_SIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAX_SIZE - 1].cur = 0;
	space[0].cur = -1;
}
void Insert(StaticList& space, ElemType x)
{
	int i = new_SL(space);
	if (i == 0) {
		cout << "ÉêÇë¿Õ¼äÊ§°Ü." << endl;
		return;
	}
	space[i].data = x;

	if (space[0].cur == -1)
		space[i].cur = -1;
	else
		space[i].cur = space[0].cur;
	space[0].cur = i;
}
void Delete(StaticList& space)
{
	int i = space[0].cur;
	space[0].cur = space[i].cur;

	delete_SL(space, i);
}
void ShowSList(const StaticList& space)
{
	int i = space[0].cur;
	while (i != -1) {
		cout << space[i].data << "-->";
		i = space[i].cur;
	}
	cout << "NULL" << endl;
}
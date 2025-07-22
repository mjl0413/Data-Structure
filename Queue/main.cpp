#include <iostream>
using namespace std;

#include "LinkQueue.h"
#include "SeqQueue.h"

int main()
{
	Queue Q;
	InitQueue(Q);

	for (int i = 1; i <= 8; i++)
		EnQueue(Q, i);
	ShowQueue(Q);

	DeQueue(Q);
	ShowQueue(Q);

	EnQueue(Q, 10);
	ShowQueue(Q);

	DestroyQueue(Q);
	return 0;
}
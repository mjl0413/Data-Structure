#include <iostream>
#include "SeqQueue.h"
using namespace std;

void InitQueue(Queue& Q)
{
	Q.base = new(nothrow) ElemType[MAX_SIZE];
	if (Q.base == nullptr)
		exit(-1);
	Q.front = Q.rear = 0;
}
void ClearQueue(Queue& Q)
{
	Q.front = Q.rear = 0;
}
void DestroyQueue(Queue& Q)
{
	Q.front = Q.rear = 0;
	delete[] Q.base;
	Q.base = nullptr;
}

void EnQueue(Queue& Q, ElemType x)
{
	/*if (Q.rear >= MAX_SIZE) {
		cout << "队列已满." << endl;
		return;
	}
	Q.base[Q.rear++] = x;*/
	if (((Q.rear + 1) % MAX_SIZE) == Q.front) {
		cout << "队列已满." << endl;
		return;
	}
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAX_SIZE;
}
void DeQueue(Queue& Q)
{
	if (Q.front == Q.rear)
		return;
	//Q.front++;
	Q.front = (Q.front + 1) % MAX_SIZE;
}
void GetHead(const Queue& Q, ElemType& e)
{
	if (Q.front == Q.rear)
		return;
	e = Q.base[Q.front];
}
int Length(const Queue& Q)
{
	//return (Q.rear - Q.front);
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}
void ShowQueue(const Queue& Q)
{
	//for (int i = Q.front; i < Q.rear; i++)
	//	cout << Q.base[i] << " ";
	for (int i = Q.front; i != Q.rear;) {
		cout << Q.base[i] << " ";
		i = (i + 1) % MAX_SIZE;
	}
	cout << endl;
}
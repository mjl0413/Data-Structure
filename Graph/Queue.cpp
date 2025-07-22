#include <iostream>
#include "Queue.h"
using namespace std;

void InitQueue(LinkQueue& Q)
{
	QueueNode* head = new(nothrow) QueueNode;
	if (head == nullptr)
		exit(-1);
	Q.front = Q.rear = head;
	Q.rear->next = nullptr;
}
bool IsEmpty(const LinkQueue& Q)
{
	return Q.front == Q.rear;
}
void ClearQueue(LinkQueue& Q)
{
	if (Q.front == Q.rear)
		return;
	QueueNode* p = Q.front->next;
	while (p != nullptr) {
		Q.front->next = p->next;
		delete p;
		p = Q.front->next;
	}
	Q.rear = Q.front;
}
void DestroyQueue(LinkQueue& Q)
{
	ClearQueue(Q);
	delete Q.front;
	Q.front = Q.rear = nullptr;
}

void EnQueue(LinkQueue& Q, QueueType x)
{
	QueueNode* s = new(nothrow) QueueNode;
	if (s == nullptr)
		exit(-1);
	s->data = x;
	s->next = nullptr;

	Q.rear->next = s;
	Q.rear = s;
}
void DeQueue(LinkQueue& Q)
{
	if (Q.front == Q.rear)
		return;

	QueueNode* p = Q.front->next;
	Q.front->next = p->next;
	if (p == Q.rear)
		Q.rear = Q.front;
	delete p;
}
void GetHead(const LinkQueue& Q, QueueType& e)
{
	if (Q.front == Q.rear)
		return;
	e = Q.front->next->data;
}
int Length(const LinkQueue& Q)
{
	int len = 0;
	QueueNode* p = Q.front->next;
	while (p != nullptr) {
		len++;
		p = p->next;
	}
	return len;
}
void ShowQueue(const LinkQueue& Q)
{
	QueueNode* p = Q.front->next;
	cout << "Front:> ";
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << "<:Rear" << endl;
}
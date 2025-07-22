#pragma once

typedef int ElemType;

struct QueueNode {
	ElemType data;
	QueueNode* next;
};
struct LinkQueue {
	QueueNode* front;
	QueueNode* rear;
};

void InitQueue(LinkQueue& Q);
bool IsEmpty(const LinkQueue& Q);
void ClearQueue(LinkQueue& Q);
void DestroyQueue(LinkQueue& Q);

void EnQueue(LinkQueue& Q, ElemType x);
void DeQueue(LinkQueue& Q);
void GetHead(const LinkQueue& Q, ElemType& e);
int Length(const LinkQueue& Q);
void ShowQueue(const LinkQueue& Q);
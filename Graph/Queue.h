#pragma once

typedef int QueueType;

struct QueueNode {
	QueueType data;
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

void EnQueue(LinkQueue& Q, QueueType x);
void DeQueue(LinkQueue& Q);
void GetHead(const LinkQueue& Q, QueueType& e);
int Length(const LinkQueue& Q);
void ShowQueue(LinkQueue& Q);
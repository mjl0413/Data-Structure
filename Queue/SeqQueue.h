#pragma once

typedef int ElemType;

#define MAX_SIZE  8
struct Queue {
	ElemType* base;
	int front;
	int rear;
};

void InitQueue(Queue& Q);
void ClearQueue(Queue& Q);
void DestroyQueue(Queue& Q);

void EnQueue(Queue& Q, ElemType x);
void DeQueue(Queue& Q);
void GetHead(const Queue& Q, ElemType& e);
int Length(const Queue& Q);
void ShowQueue(const Queue& Q);
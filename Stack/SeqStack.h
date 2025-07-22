#pragma once

typedef char ElemType;

#define STACK_INIT_SIZE  8
#define STACK_INC_SIZE   3
struct SeqStack {
	ElemType* base;
	int top;
	int capacity;
};

void InitStack(SeqStack& s);
bool Inc(SeqStack& s);
void Clear(SeqStack& s);
void Destroy(SeqStack& s);

bool IsFull(const SeqStack& s);
bool IsEmpty(const SeqStack& s);
int Length(const SeqStack& s);

void Push(SeqStack& s, ElemType x);
void Pop(SeqStack& s);
bool GetTop(const SeqStack& s, ElemType& e);
void Show(const SeqStack& s);
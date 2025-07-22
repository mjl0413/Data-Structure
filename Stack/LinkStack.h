#pragma once

struct AVLNode;
typedef AVLNode* ElemType;

struct StackNode {
	ElemType data;
	StackNode* next;
};
typedef StackNode* LinkStack;

void InitStack(LinkStack& s);
void DestroyStack(LinkStack& s);
bool IsEmpty(const LinkStack& s);

void Push(LinkStack& s, ElemType x);
void Pop(LinkStack& s);
ElemType GetTop(const LinkStack& s);
void Show(const LinkStack& s);
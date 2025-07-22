#pragma once

struct AVLNode;
typedef AVLNode* StackType;

struct StackNode {
	StackType data;
	StackNode* next;
};
typedef StackNode* LinkStack;

void InitStack(LinkStack& s);
void DestroyStack(LinkStack& s);
bool IsEmpty(const LinkStack& s);

void Push(LinkStack& s, StackType x);
void Pop(LinkStack& s);
StackType GetTop(const LinkStack& s);
void Show(const LinkStack& s);
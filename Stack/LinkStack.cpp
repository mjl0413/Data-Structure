#include <iostream>
#include "LinkStack.h"
using namespace std;

void InitStack(LinkStack& s)
{
	s = nullptr;
}
void DestroyStack(LinkStack& s)
{
	if (s != nullptr)
	{
		DestroyStack(s->next);
		delete s;
	}
}
bool IsEmpty(const LinkStack& s)
{
	return s == nullptr;
}

void Push(LinkStack& s, ElemType x)
{
	StackNode* t = new(nothrow) StackNode;
	if (t == nullptr)
		exit(-1);
	t->data = x;

	//Í·²å
	if (s == nullptr) {
		s = t;
		s->next = nullptr;
	}
	else {
		t->next = s;
		s = t;
	}
}
void Pop(LinkStack& s)
{
	StackNode* p = s;
	s = p->next;
	delete p;
	p = nullptr;
}
ElemType GetTop(const LinkStack& s)
{
	StackNode* p = s;
	if (p == nullptr)
		exit(-1);
	return p->data;
}
void Show(const LinkStack& s)
{
	StackNode* p = s;
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << endl;
}
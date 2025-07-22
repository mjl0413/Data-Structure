#include <iostream>
#include "SeqStack.h"
using namespace std;

void InitStack(SeqStack& s)
{
	s.base = new(nothrow) ElemType[STACK_INIT_SIZE];
	if (s.base == nullptr)
		exit(-1);
	s.top = 0;
	s.capacity = STACK_INIT_SIZE;
}
bool Inc(SeqStack& s)
{
	ElemType* newbase = (ElemType*)realloc(s.base, sizeof(ElemType) * (s.capacity + STACK_INC_SIZE));
	if (newbase == nullptr) {
		cout << "ÄÚ´æºÄ¾¡." << endl;
		return false;
	}
	s.base = newbase;
	s.capacity += STACK_INC_SIZE;
	return true;
}
void Clear(SeqStack& s)
{
	s.top = 0;
}
void Destroy(SeqStack& s)
{
	delete[] s.base;
	s.base = nullptr;
	s.capacity = s.top = 0;
}

bool IsFull(const SeqStack& s)
{
	return s.top >= s.capacity;
}
bool IsEmpty(const SeqStack& s)
{
	return s.top == 0;
}
int Length(const SeqStack& s)
{
	return s.top;
}

void Push(SeqStack& s, ElemType x)
{
	if (IsFull(s) && !Inc(s)) {
		cout << "Õ»¿Õ¼äÒÑÂú." << endl;
		return;
	}
	s.base[s.top++] = x;
}
void Pop(SeqStack& s)
{
	if (IsEmpty(s)) {
		cout << "Õ»Îª¿Õ." << endl;
		return;
	}
	s.top--;
}
bool GetTop(const SeqStack& s, ElemType& e)
{
	if (IsEmpty(s)) {
		cout << "Õ»Îª¿Õ." << endl;
		return false;
	}
	e = s.base[s.top - 1];
	return true;
}
void Show(const SeqStack& s)
{
	int i = s.top - 1;
	for (i; i >= 0; i--)
		cout << s.base[i] << endl;
	cout << endl;
}
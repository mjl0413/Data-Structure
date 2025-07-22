#pragma once

#include <iostream>
using namespace std;

struct BinTreeNode;
enum TAG {
	LEFT,
	RIGHT
};
struct PostNode {
	BinTreeNode* ptr;
	TAG tag;
};
typedef PostNode PostType;

#define STACK_INIT_SIZE  8
#define STACK_INC_SIZE   3
struct SeqStack {
	PostType* base;
	int top;
	int capacity;
};

void Post_InitStack(SeqStack& s)
{
	s.base = new(nothrow) PostType[STACK_INIT_SIZE];
	if (s.base == nullptr)
		exit(-1);
	s.top = 0;
	s.capacity = STACK_INIT_SIZE;
}
bool Post_Inc(SeqStack& s)
{
	PostType* newbase = (PostType*)realloc(s.base, sizeof(PostType) * (s.capacity + STACK_INC_SIZE));
	if (newbase == nullptr) {
		cout << "ÄÚ´æºÄ¾¡." << endl;
		return false;
	}
	s.base = newbase;
	s.capacity += STACK_INC_SIZE;
	return true;
}
void Post_Destroy(SeqStack& s)
{
	delete[] s.base;
	s.base = nullptr;
	s.capacity = s.top = 0;
}
bool Post_IsFull(const SeqStack& s)
{
	return s.top >= s.capacity;
}
bool Post_IsEmpty(const SeqStack& s)
{
	return s.top == 0;
}
void Post_Push(SeqStack& s, PostType x)
{
	if (Post_IsFull(s) && !Post_Inc(s)) {
		cout << "Õ»¿Õ¼äÒÑÂú." << endl;
		return;
	}
	s.base[s.top++] = x;
}
void Post_Pop(SeqStack& s)
{
	if (Post_IsEmpty(s)) {
		cout << "Õ»Îª¿Õ." << endl;
		return;
	}
	s.top--;
}
bool Post_GetTop(const SeqStack& s, PostType& e)
{
	if (Post_IsEmpty(s)) {
		cout << "Õ»Îª¿Õ." << endl;
		return false;
	}
	e = s.base[s.top - 1];
	return true;
}

void PostOrder_2(BinTreeNode* t)
{
	SeqStack st;
	Post_InitStack(st);
	PostNode sn = { nullptr,LEFT };
	do
	{
		while (t != nullptr) {
			sn.ptr = t;
			sn.tag = LEFT;
			Post_Push(st, sn);
			t = t->leftChild;
		}
		while (!Post_IsEmpty(st)) {
			Post_GetTop(st, sn);
			Post_Pop(st);
			if (sn.tag == LEFT) {
				sn.tag = RIGHT;
				Post_Push(st, sn);
				t = sn.ptr->rightChild;
				break;
			}
			else if (sn.tag == RIGHT)
				cout << sn.ptr->data << " ";
		}
	} while (!Post_IsEmpty(st));

	cout << endl;
	Post_Destroy(st);
}
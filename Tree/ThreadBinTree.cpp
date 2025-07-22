#include <iostream>
#include "ThreadBinTree.h"
using namespace std;

void InitTBinTree(TBinTree& bt, ElemType ref)
{
	bt.root = nullptr;
	bt.refvalue = ref;
}
void CreateTBinTree(TBinTree& bt, TBinTreeNode*& t, const char*& str)
{
	if (*str == bt.refvalue) {
		t = nullptr;
		return;
	}
	t = new(nothrow) TBinTreeNode;
	if (t == nullptr)
		exit(-1);
	t->data = *str;
	t->leftChild = t->rightChild = nullptr;
	t->LTag = t->RTag = LINK;

	CreateTBinTree(bt, t->leftChild, ++str);
	CreateTBinTree(bt, t->rightChild, ++str);
}
void ClearTBinTree(TBinTreeNode*& t)
{
	if (t != nullptr) {
		if (t->LTag == LINK)
			ClearTBinTree(t->leftChild);
		if (t->RTag == LINK)
			ClearTBinTree(t->rightChild);
		delete t;
		t = nullptr;
	}
}

void CreatInThread(TBinTree& bt)
{
	TBinTreeNode* pre = nullptr;
	CreatInThread(bt.root, pre);
	pre->RTag = THREAD;
}
void CreatInThread(TBinTreeNode*& t, TBinTreeNode*& pre)
{
	if (t == nullptr)
		return;
	CreatInThread(t->leftChild, pre);

	if (t->leftChild == nullptr) {
		t->LTag = THREAD;
		t->leftChild = pre;
	}
	if (pre != nullptr && pre->rightChild == nullptr) {
		pre->RTag = THREAD;
		pre->rightChild = t;
	}
	pre = t;
	CreatInThread(t->rightChild, pre);
}

TBinTreeNode* First(TBinTreeNode* t) 
{
	if (t == nullptr)
		return nullptr;
	TBinTreeNode* p = t;
	while (p->LTag == LINK)
		p = p->leftChild;
	return p;
}
TBinTreeNode* Last(TBinTreeNode* t)
{
	if (t == nullptr)
		return nullptr;
	TBinTreeNode* p = t;
	while (p->LTag == THREAD)
		p = p->rightChild;
	return p;
}
TBinTreeNode* Next(TBinTreeNode* t, TBinTreeNode* cur)
{
	if (t == nullptr || cur == nullptr)
		return nullptr;
	if (cur->RTag == THREAD)
		return cur->rightChild;
	return First(cur->rightChild);
}
TBinTreeNode* Prio(TBinTreeNode* t, TBinTreeNode* cur)
{
	if (t == nullptr || cur == nullptr)
		return nullptr;
	if (cur->LTag == THREAD)
		return cur->leftChild;
	return Last(cur->leftChild);
}
void InOrder(TBinTreeNode* const t)
{
	for (TBinTreeNode* p = First(t); p != nullptr; p = Next(t, p))
		cout << p->data << " ";
	cout << endl;
}
TBinTreeNode* Search(TBinTreeNode* t, ElemType key)
{
	if (t == nullptr)
		return nullptr;
	for (TBinTreeNode* p = First(t); p != nullptr; p = Next(t, p))
		if (p->data == key)
			return p;
	return nullptr;
}
TBinTreeNode* Parent(TBinTreeNode* t, TBinTreeNode* cur)
{
	if (t == nullptr || cur == nullptr || t == cur)
		return nullptr;

	TBinTreeNode* p = nullptr;
	if (cur->LTag == THREAD) {
		p = cur->leftChild;
		if (p->rightChild == cur)
			return p;
	}
	if (cur->RTag == THREAD) {
		p = cur->rightChild;
		if (p->leftChild == cur)
			return p;
	}

	p = First(cur->leftChild);
	p = p->leftChild;
	if (p != nullptr && p->rightChild == cur)
		return p;

	p = Last(cur->rightChild);
	return p->rightChild;
}
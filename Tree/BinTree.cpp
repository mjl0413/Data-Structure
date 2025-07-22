#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "BinTree.h"
using namespace std;

void InitBinTree(BinTree& bt, ElemType ref)
{
	bt.root = nullptr;
	bt.refvalue = ref;
}
bool IsEmpty(const BinTree& bt)
{
	return bt.root == nullptr;
}
void CopyTree(BinTreeNode*& t1, BinTreeNode*& t2)
{
	if (t1 == nullptr)
		t2 = nullptr;
	else {
		t2 = new(nothrow) BinTreeNode;
		if (t2 == nullptr)
			exit(-1);
		t2->data = t1->data;
		CopyTree(t1->leftChild, t2->leftChild);
		CopyTree(t1->rightChild, t2->rightChild);
	}
	
}
void ClearBinTree(BinTreeNode*& t)
{
	if (t != nullptr) {
		ClearBinTree(t->leftChild);
		ClearBinTree(t->rightChild);
		delete t;
		t = nullptr;
	}
}

void CreateBinTree_1(BinTree& bt, BinTreeNode*& t)
{
	ElemType Item;
	cin >> Item;
	if (Item == bt.refvalue)
		t = nullptr;
	else {
		t = new(nothrow) BinTreeNode;
		if (t == nullptr)
			exit(-1);
		t->data = Item;
		CreateBinTree_1(bt, t->leftChild);
		CreateBinTree_1(bt, t->rightChild);
	}
}
void CreateBinTree_2(BinTree& bt, BinTreeNode*& t, const char*& str)
{
	if (*str == bt.refvalue)
		t = nullptr;
	else {
		t = new(nothrow) BinTreeNode;
		if (t == nullptr)
			exit(-1);
		t->data = *str;
		CreateBinTree_2(bt, t->leftChild, ++str);
		CreateBinTree_2(bt, t->rightChild, ++str);
	}
}
void CreateBinTree_3(BinTreeNode*& t, const char* VLR, const char* LVR, const int n)
{
	if (n == 0) {
		t = nullptr;
		return;
	}
	int k = 0;
	while (VLR[0] != LVR[k])
		k++;
	t = new(nothrow) BinTreeNode;
	if (t == nullptr)
		exit(-1);
	t->data = LVR[k];
	
	CreateBinTree_3(t->leftChild, VLR + 1, LVR, k);
	CreateBinTree_3(t->rightChild, VLR + k + 1, LVR + k + 1, n - k - 1);
}
void CreateBinTree_4(BinTreeNode*& t, const char* LRV, const char* LVR, const int n)
{
	if (n == 0) {
		t = nullptr;
		return;
	}
	int k = 0;
	while (LRV[n - 1] != LVR[k])
		k++;
	t = new(nothrow) BinTreeNode;
	if (t == nullptr)
		exit(-1);
	t->data = LVR[k];

	CreateBinTree_4(t->rightChild, LRV + k, LVR + k + 1, n - k - 1);
	CreateBinTree_4(t->leftChild, LRV, LVR, k);
}

void PreOrder_1(const BinTreeNode* t)
{
	if (t != nullptr) {
		cout << t->data << " ";
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}
void InOrder_1(const BinTreeNode* t)
{
	if (t != nullptr) {
		InOrder_1(t->leftChild);
		cout << t->data << " ";
		InOrder_1(t->rightChild);
	}
}
void PostOrder_1(const BinTreeNode* t)
{
	if (t != nullptr) {
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		cout << t->data << " ";
	}
}

void PreOrder_2(BinTreeNode* const t)
{
	SeqStack st;
	InitStack(st);
	if (t != nullptr)
	{
		BinTreeNode* p;
		Push(st, t);
		while (!IsEmpty(st)) {
			GetTop(st, p);
			Pop(st);
			cout << p->data << " ";
			if (p->rightChild != nullptr)
				Push(st, p->rightChild);
			if (p->leftChild != nullptr)
				Push(st, p->leftChild);
		}
	}
	cout << endl;
	Destroy(st);
}
void InOrder_2(BinTreeNode* t)
{
	SeqStack st;
	InitStack(st);
	if (t != nullptr)
	{
		Push(st, t);
		while (!IsEmpty(st)) {
			while (t->leftChild != nullptr) {
				Push(st, t->leftChild);
				t = t->leftChild;
			}
			BinTreeNode* p;
			GetTop(st, p);
			Pop(st);
			cout << p->data << " ";

			if (p->rightChild != nullptr) {
				t = p->rightChild;
				Push(st, t);
			}
		}
	}
	cout << endl;
	Destroy(st);
}
void LevelOrder(BinTreeNode* const t)
{
	LinkQueue Q;
	InitQueue(Q);
	if (t != nullptr) {
		EnQueue(Q, t);

		while (!IsEmpty(Q)) {
			BinTreeNode* p;
			GetHead(Q, p);
			DeQueue(Q);
			cout << p->data << " ";
			if (p->leftChild != nullptr)
				EnQueue(Q, p->leftChild);
			if (p->rightChild != nullptr)
				EnQueue(Q, p->rightChild);
		}
	}
	cout << endl;
	DestroyQueue(Q);
}

int Size(const BinTreeNode* t)
{
	if (t == nullptr)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}
int Height(const BinTreeNode* t)
{
	if (t == nullptr)
		return 0;
	else {
		int left = Height(t->leftChild);
		int right = Height(t->rightChild);
		return 1 + (left > right ? left : right);
	}
}
BinTreeNode* Search(BinTreeNode* t, ElemType key)
{
	if (t == nullptr)
		return nullptr;
	if (t->data == key)
		return t;

	BinTreeNode* p = Search(t->leftChild, key);
	if (p != nullptr)
		return p;
	return Search(t->rightChild, key);
}
BinTreeNode* Parent(BinTreeNode* t, const BinTreeNode* p)
{
	if (t == nullptr || p == nullptr)
		return nullptr;
	if (t->leftChild == p || t->rightChild == p)
		return t;

	BinTreeNode* q = Parent(t->leftChild, p);
	if (q != nullptr)
		return q;
	return Parent(t->rightChild, p);
}
BinTreeNode* LeftChild(const BinTreeNode* p)
{
	if (p != nullptr)
		return p->leftChild;
	return nullptr;
}
BinTreeNode* RightChild(const BinTreeNode* p)
{
	if (p != nullptr)
		return p->rightChild;
	return nullptr;
}

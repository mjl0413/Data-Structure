#include <iostream>
#include "BST.h"
using namespace std;

void InitBST(BST& bst)
{
	bst = nullptr;
}
void DestroyBST(BST& bst)
{
	if (bst != nullptr)
	{
		DestroyBST(bst->leftChild);
		DestroyBST(bst->rightChild);
		delete bst;
	}
}

BOOL InsertBST(BST& t, T x)
{
	if (t == nullptr) {
		t = new(nothrow) BSTNode;
		if (t == nullptr)
			exit(-1);
		t->data = x;
		t->leftChild = t->rightChild = nullptr;
		return TRUE;
	}
	else if (x < t->data)
		InsertBST(t->leftChild, x);
	else if (x > t->data)
		InsertBST(t->rightChild, x);

	return FALSE;
}
BOOL RemoveBST(BST& t, T key)
{
	if (t == nullptr)
		return FALSE;

	if (key < t->data)
		return RemoveBST(t->leftChild, key);
	else if (key > t->data)
		return RemoveBST(t->rightChild, key);
	else
	{
		BSTNode* p = nullptr;
		if (t->leftChild != nullptr && t->rightChild != nullptr) {
			p = t->rightChild;
			while (p->leftChild != nullptr)
				p = p->leftChild;
			t->data = p->data;
			RemoveBST(t->rightChild, p->data);
		}
		else {
			p = t;
			if (t->leftChild == nullptr)
				t = t->rightChild;
			else
				t = t->rightChild;
			delete p;
			p = nullptr;
		}
		/*BSTNode* p = nullptr;
		if (t->leftChild == nullptr && t->rightChild == nullptr) {
			delete t;
			t = nullptr;
		}
		else if (t->leftChild != nullptr && t->rightChild == nullptr) {
			p = t;
			t = t->leftChild;
			delete p;
		}
		else if (t->leftChild == nullptr && t->rightChild != nullptr) {
			p = t;
			t = t->rightChild;
			delete p;
		}
		else {
			p = t->rightChild;
			while (p->leftChild != nullptr)
				p = p->leftChild;
			t->data = p->data;
			return RemoveBST(t->rightChild, p->data);
		}
		p = nullptr;*/
	}
	return TRUE;
}


T Min(BST t)
{
	if (t == nullptr)
		return INT_MIN;
	while (t->leftChild != nullptr)
		t = t->leftChild;
	return t->data;
}
T Max(BST t)
{
	if (t == nullptr)
		return INT_MAX;
	while (t->rightChild != nullptr)
		t = t->rightChild;
	return t->data;
}
void Sort(const BST& t)
{
	if (t != nullptr)
	{
		Sort(t->leftChild);
		cout << t->data << "  ";
		Sort(t->rightChild);
	}
}
BSTNode* Search(const BST t, T key)
{
	if (t == nullptr)
		return nullptr;
	if (t->data == key)
		return t;

	if (key < t->data)
		return Search(t->leftChild, key);
	else
		return Search(t->rightChild, key);
}
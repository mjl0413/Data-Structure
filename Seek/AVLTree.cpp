#include <iostream>
#include "AVLTree.h"
#include "Stack.h"
using namespace std;

void InitAVL(AVLTree& avl)
{
	avl = nullptr;
}

static AVLNode* BuyNode(const Type x)
{
	AVLNode* p = new(nothrow) AVLNode;
	if (p == nullptr)
		exit(-1);
	p->data = x;
	p->leftChild = p->rightChild = nullptr;
	p->bf = 0;
	return p;
}

void RotateR(AVLNode*& ptr)
{
	AVLNode* subR = ptr;
	ptr = subR->leftChild;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;

	ptr->bf = subR->bf = 0;
}
void RotateL(AVLNode*& ptr)
{
	AVLNode* subL = ptr;
	ptr = subL->rightChild;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	ptr->bf = subL->bf = 0;
}
void RotateRL(AVLNode*& ptr)
{
	AVLNode* subL = ptr;
	AVLNode* subR = subL->rightChild;
	ptr = subR->leftChild;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	if (ptr->bf == 1)
		subL->bf = -1;
	else
		subL->bf = 0;

	ptr->bf = 0;
}
void RotateLR(AVLNode*& ptr)
{
	AVLNode* subR = ptr;
	AVLNode* subL = subR->leftChild;
	ptr = subL->rightChild;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	if (ptr->bf <= 0)
		subL->bf = 0;
	else
		subL->bf = -1;

	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	if (ptr->bf == -1)
		subR->bf = 1;
	else
		subR->bf = 0;

	ptr->bf = 0;
}

BOOL InsertAVL(AVLTree& t, Type x)
{
	LinkStack st;
	InitStack(st);

	AVLNode* p = t, * parent = nullptr;
	while (p != nullptr)
	{
		if (x == p->data)
			return FALSE;
		parent = p;
		Push(st, parent);
		if (x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = BuyNode(x);

	//根节点
	if (parent == nullptr) {
		t = p;
		DestroyStack(st);
		return TRUE;
	}
	if (x < parent->data)
		parent->leftChild = p;
	else
		parent->rightChild = p;

	//调整bf
	while (!IsEmpty(st))
	{
		parent = GetTop(st);
		Pop(st);
		if (parent->leftChild == p)
			parent->bf--;
		else
			parent->bf++;

		if (parent->bf == 0)
			break;
		//向上回溯检查
		else if (parent->bf == 1 || parent->bf == -1)
			p = parent;
		//旋转平衡调整
		else
		{
			//符号标记：左树高为负，右树高为正
			int flag = (parent->bf < 0) ? -1 : 1;
			//处于直线，单旋转
			if (p->bf == flag) {
				if (flag == -1)
					// / 右旋转
					RotateR(parent);
				else
					// \ 左旋转 
					RotateL(parent);
			}
			//处于折线，双旋转
			else {
				if (flag == -1)
					// > 先右后左
					RotateRL(parent);
				else
					// < 先左后右
					RotateLR(parent);
			}
			break;
		}
	}
	if (IsEmpty(st))
		t = parent;
	else {
		AVLNode* q = GetTop(st);
		if (q->data > parent->data)
			q->leftChild = parent;
		else
			q->rightChild = parent;
	}

	DestroyStack(st);
	return TRUE;
}
BOOL RemoveAVL(AVLTree& t, Type key)
{
	LinkStack st;
	InitStack(st);

	AVLNode* p = t, * parent = nullptr;
	//父的父节点
	AVLNode* pparent = nullptr;
	while (p != nullptr) {
		if (p->data == key)
			break;
		parent = p;
		Push(st, parent);
		if (key < p->data)
			p = p->leftChild;
		else if (key > p->data)
			p = p->rightChild;
	}
	if (p == nullptr)
		return FALSE;

	AVLNode* q = nullptr;
	int f = -1;  //表示leftChild为空（0）或rightChild为空（1）
	if (p->leftChild != nullptr && p->rightChild != nullptr)
	{
		parent = p;
		Push(st, parent);
		q = p->leftChild;
		while (q->rightChild != nullptr) {
			parent = p;
			Push(st, parent);
			q = q->rightChild;
		}
		p->data = q->data;
		p = q;
	}

	if (p->leftChild != nullptr)
		q = p->leftChild;
	else
		q = p->rightChild;

	if (parent == nullptr)
		t = parent;
	else {
		if (parent->leftChild == p) {
			parent->leftChild = q;
			f = 0;
		}
		else if (parent->rightChild == p) {
			parent->rightChild = q;
			f = 1;
		}

		//parent处于左子树为-1，右子树为1，都不连（parent为根节点）为0
		int link_flag = 0;
		while (!IsEmpty(st))
		{
			parent = GetTop(st);
			Pop(st);
			if (parent->leftChild == q && f == 0)
				parent->bf++;
			else
				parent->bf--;

			if (!IsEmpty(st)) {
				pparent = GetTop(st);
				link_flag = (pparent->leftChild == parent) ? -1 : 1;
			}
			else
				link_flag = 0;

			if (parent->bf == 0)
				q = parent;
			else if (parent->bf == -1 || parent->bf == 1)
				break;
			else
			{
				int flag = 0;
				if (parent->bf < 0) {
					flag = -1;
					q = parent->leftChild;
				}
				else if (parent->bf > 0) {
					flag = 1;
					q = parent->rightChild;
				}

				if (q->bf == 0) {
					if (flag == -1) {
						// / 右旋转
						RotateR(parent);
						parent->bf = 1;
						parent->rightChild->bf = -1;
					}
					else {
						// \ 左旋转 
						RotateL(parent);
						parent->bf = -1;
						parent->leftChild->bf = 1;
					}
					break;
				}

				if (q->bf == flag) {
					if (flag == -1)
						RotateR(parent);
					else
						RotateL(parent);
				}
				else{
					if (flag == -1)
						RotateLR(parent);
					else
						RotateRL(parent);
				}

				if (link_flag == 1)
					pparent->rightChild = parent;
				else if (link_flag == -1)
					pparent->leftChild = parent;
			}
		}

		if (IsEmpty(st))
			t = parent;
	}
	delete p;

	DestroyStack(st);
	return TRUE;
}
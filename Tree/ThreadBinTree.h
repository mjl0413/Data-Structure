#pragma once

typedef char ElemType;

enum TAG_TYPE {
	LINK,
	THREAD
};
struct TBinTreeNode {
	ElemType data;
	TBinTreeNode* leftChild;
	TBinTreeNode* rightChild;
	TAG_TYPE LTag;
	TAG_TYPE RTag;
};
struct TBinTree {
	TBinTreeNode* root;
	ElemType refvalue;
};

void InitTBinTree(TBinTree& bt, ElemType ref);
void CreateTBinTree(TBinTree& bt, TBinTreeNode*& t, const char*& str);
void ClearTBinTree(TBinTreeNode*& t);

//������������CBEDFAGH
void CreatInThread(TBinTree& bt);
void CreatInThread(TBinTreeNode*& t, TBinTreeNode*& pre);
/* ���һ���ڵ� */
TBinTreeNode* First(TBinTreeNode* t);
/* �����һ���ڵ� */
TBinTreeNode* Last(TBinTreeNode* t);
/* ���̽ڵ� */
TBinTreeNode* Next(TBinTreeNode* t, TBinTreeNode* cur);
/* ��ǰ���ڵ� */
TBinTreeNode* Prio(TBinTreeNode* t, TBinTreeNode* cur);
/* ������� */
void InOrder(TBinTreeNode* const t);
/* ���� */
TBinTreeNode* Search(TBinTreeNode* t, ElemType key);
/* �󸸽ڵ� */
TBinTreeNode* Parent(TBinTreeNode* t, TBinTreeNode* cur);

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

//中序线索化：CBEDFAGH
void CreatInThread(TBinTree& bt);
void CreatInThread(TBinTreeNode*& t, TBinTreeNode*& pre);
/* 求第一个节点 */
TBinTreeNode* First(TBinTreeNode* t);
/* 求最后一个节点 */
TBinTreeNode* Last(TBinTreeNode* t);
/* 求后继节点 */
TBinTreeNode* Next(TBinTreeNode* t, TBinTreeNode* cur);
/* 求前驱节点 */
TBinTreeNode* Prio(TBinTreeNode* t, TBinTreeNode* cur);
/* 中序遍历 */
void InOrder(TBinTreeNode* const t);
/* 查找 */
TBinTreeNode* Search(TBinTreeNode* t, ElemType key);
/* 求父节点 */
TBinTreeNode* Parent(TBinTreeNode* t, TBinTreeNode* cur);

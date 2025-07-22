#pragma once

typedef char ElemType;

struct BinTreeNode {
	ElemType data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
};
struct BinTree {
	BinTreeNode* root;
	ElemType refvalue;  //标记空节点
};

void InitBinTree(BinTree& bt, ElemType ref);
bool IsEmpty(const BinTree& bt);
//将t1复制到t2
void CopyTree(BinTreeNode*& t1, BinTreeNode*& t2);
void ClearBinTree(BinTreeNode*& t);

/* 创建 */ 
void CreateBinTree_1(BinTree& bt, BinTreeNode*& t);
void CreateBinTree_2(BinTree& bt, BinTreeNode*& t, const char*& str);
//根据前序(VLR)和中序(LVR)创建
void CreateBinTree_3(BinTreeNode*& t, const char* VLR, const char* LVR, const int n);
//根据后序(LRV)和中序(LVR)创建
void CreateBinTree_4(BinTreeNode*& t, const char* LRV, const char* LVR, const int n);

/* 递归遍历 */
//先序遍历
void PreOrder_1(const BinTreeNode* t);
//中序遍历
void InOrder_1(const BinTreeNode* t);
//后序遍历
void PostOrder_1(const BinTreeNode* t);
/* 非递归遍历 */
//先序遍历
void PreOrder_2(BinTreeNode* const t);
//中序遍历
void InOrder_2(BinTreeNode* t);
//层序遍历
void LevelOrder(BinTreeNode* const t);

/* 功能实现 */
//求节点个数
int Size(const BinTreeNode* t);
//求树高度
int Height(const BinTreeNode* t);
//查找节点
BinTreeNode* Search(BinTreeNode* t, ElemType key);
//查找p的父节点
BinTreeNode* Parent(BinTreeNode* t, const BinTreeNode* p);
//查找左子树
BinTreeNode* LeftChild(const BinTreeNode* p);
//查找右子树
BinTreeNode* RightChild(const BinTreeNode* p);

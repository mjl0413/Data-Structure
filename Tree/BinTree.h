#pragma once

typedef char ElemType;

struct BinTreeNode {
	ElemType data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
};
struct BinTree {
	BinTreeNode* root;
	ElemType refvalue;  //��ǿսڵ�
};

void InitBinTree(BinTree& bt, ElemType ref);
bool IsEmpty(const BinTree& bt);
//��t1���Ƶ�t2
void CopyTree(BinTreeNode*& t1, BinTreeNode*& t2);
void ClearBinTree(BinTreeNode*& t);

/* ���� */ 
void CreateBinTree_1(BinTree& bt, BinTreeNode*& t);
void CreateBinTree_2(BinTree& bt, BinTreeNode*& t, const char*& str);
//����ǰ��(VLR)������(LVR)����
void CreateBinTree_3(BinTreeNode*& t, const char* VLR, const char* LVR, const int n);
//���ݺ���(LRV)������(LVR)����
void CreateBinTree_4(BinTreeNode*& t, const char* LRV, const char* LVR, const int n);

/* �ݹ���� */
//�������
void PreOrder_1(const BinTreeNode* t);
//�������
void InOrder_1(const BinTreeNode* t);
//�������
void PostOrder_1(const BinTreeNode* t);
/* �ǵݹ���� */
//�������
void PreOrder_2(BinTreeNode* const t);
//�������
void InOrder_2(BinTreeNode* t);
//�������
void LevelOrder(BinTreeNode* const t);

/* ����ʵ�� */
//��ڵ����
int Size(const BinTreeNode* t);
//�����߶�
int Height(const BinTreeNode* t);
//���ҽڵ�
BinTreeNode* Search(BinTreeNode* t, ElemType key);
//����p�ĸ��ڵ�
BinTreeNode* Parent(BinTreeNode* t, const BinTreeNode* p);
//����������
BinTreeNode* LeftChild(const BinTreeNode* p);
//����������
BinTreeNode* RightChild(const BinTreeNode* p);

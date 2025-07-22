#pragma once

#define TRUE  1
#define FALSE 0
#define BOOL  int

typedef int Type;

struct AVLNode {
	Type data;
	AVLNode* leftChild;
	AVLNode* rightChild;
	int bf;  //ÓÒÊý¸ß-×óÊ÷¸ß
};
typedef AVLNode* AVLTree;

void InitAVL(AVLTree& avl);

void RotateR(AVLNode*& ptr);
void RotateL(AVLNode*& ptr);
void RotateRL(AVLNode*& ptr);
void RotateLR(AVLNode*& ptr);

BOOL InsertAVL(AVLTree& t, Type x);
BOOL RemoveAVL(AVLTree& t, Type key);
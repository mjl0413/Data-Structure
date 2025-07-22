#pragma once

#define TRUE  1
#define FALSE 0
#define BOOL  int

typedef int T;

struct BSTNode {
	T data;
	BSTNode* leftChild;
	BSTNode* rightChild;
};
typedef BSTNode* BST;

void InitBST(BST& bst);
void DestroyBST(BST& bst);

BOOL InsertBST(BST& t, T x);
BOOL RemoveBST(BST& t, T key);

T Min(BST t);
T Max(BST t);
void Sort(const BST& t);
BSTNode* Search(const BST t, T key);
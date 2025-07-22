#include <iostream>
using namespace std;

#include "BST.h"
#include "AVLTree.h"
#include "HashTable.h"

#define BST   0
#define AVL   0
#define HASH  1

int main()
{
#if   BST
	T a[] = { 45,12,53,3,37,100,24,61,90,78 };
	int n = sizeof(a) / sizeof(T);

	BST root;
	InitBST(root);
	for (int i = 0; i < n; i++)
		InsertBST(root, a[i]);

	Sort(root);
	cout << endl;
	RemoveBST(root, 12);

	DestroyBST(root);

#elif AVL
	Type a[] = { 50,40,60,10,45,70,5,30,48 };
	int n = sizeof(a) / sizeof(Type);

	AVLTree avl;
	InitAVL(avl);
	for (int i = 0; i < n; i++)
		InsertAVL(avl, a[i]);

	Type key = 48;
	RemoveAVL(avl, key);

#elif HASH
	HashTable ht;
	InitHashTable(ht);

	ElemType ar[] = { 19,14,23,1,68,20,84,27,55,11,10,79 };
	int n = sizeof(ar) / sizeof(ElemType);

	for (int i = 0; i < n; i++)
		InsertHashTable(ht, ar[i]);
	ShowHashTable(ht);
#endif
	return 0;
}
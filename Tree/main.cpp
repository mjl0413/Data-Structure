#include <iostream>
#include <cstring>
using namespace std;

#include "BinTree.h"
#include "PostOrder_2.hpp"
#include "ThreadBinTree.h"
#include "Tree.h"

#define BISIC     0
#define THREAD    0
#define FOREST    1

int main()
{
	const char* str1 = "ABC##DE##F##G#H##";

#if BISIC
	const char* VLR = "ABCDEFGH";
	const char* LVR = "CBEDFAGH";
	const char* LRV = "CEFDBHGA";
	const int n = strlen(LVR);

	BinTree mytree;
	InitBinTree(mytree, '#');
	CreateBinTree_4(mytree.root, LRV, LVR, n);

	PreOrder_2(mytree.root);
	InOrder_2(mytree.root);
	PostOrder_2(mytree.root);
	LevelOrder(mytree.root);
	cout << endl;

	cout << "Size=" << Size(mytree.root) << endl;
	cout << "Height=" << Height(mytree.root) << endl;

	ClearBinTree(mytree.root);

#elif THREAD
	TBinTree mytree;
	InitTBinTree(mytree, '#');
	CreateTBinTree(mytree, mytree.root, str1);
	CreatInThread(mytree);

	InOrder(mytree.root);

	ClearTBinTree(mytree.root);

#elif FOREST
	Tree tree;
	InitTree(tree, '#');

	//二叉树前序表示，N个节点有N+1个空指针
	const char* str2 = "RAD#E##B#CFG#H#K#####";
	CreateTree(tree, tree.root, str2);
	TreeNode* p = Find(tree.root, 'D');
	TreeNode* parent = Parent(tree.root, p);

#endif
	return 0;
}
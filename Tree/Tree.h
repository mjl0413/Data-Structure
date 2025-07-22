#pragma once

typedef char ElemType;

struct TreeNode {
	ElemType data;
	TreeNode* firstChild;  //×ó×ÓÊ÷
	TreeNode* nextSibling; //ÓÒ×ÓÊ÷
};
struct Tree {
	TreeNode* root;
	ElemType refvalue;
};

void InitTree(Tree& tree, ElemType ref);
void CreateTree(Tree& tree, TreeNode*& t, const char*& str);

TreeNode* Root(const Tree tree);
TreeNode* FirstChild(const TreeNode* t);
TreeNode* NextSibling(const TreeNode* t);
TreeNode* Find(TreeNode* const t, ElemType key);
TreeNode* Parent(TreeNode* const t, TreeNode* p);
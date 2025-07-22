#include <iostream>
#include "Tree.h"
using namespace std;

void InitTree(Tree& tree, ElemType ref)
{
	tree.root = nullptr;
	tree.refvalue = ref;
}
void CreateTree(Tree& tree, TreeNode*& t, const char*& str)
{
	if (*str == tree.refvalue) {
		t = nullptr;
		return;
	}

	t = new(nothrow) TreeNode;
	if (t == nullptr)
		exit(-1);
	t->data = *str;
	CreateTree(tree, t->firstChild, ++str);
	CreateTree(tree, t->nextSibling, ++str);
}

TreeNode* Root(const Tree tree)
{
	return tree.root;
}
TreeNode* FirstChild(const TreeNode* t)
{
	if (t == nullptr)
		return nullptr;
	return t->firstChild;
}
TreeNode* NextSibling(const TreeNode* t)
{
	if (t == nullptr)
		return nullptr;
	return t->nextSibling;
}
TreeNode* Find(TreeNode* const t, ElemType key)
{
	if (t == nullptr)
		return nullptr;
	if (t->data == key)
		return t;

	TreeNode* p = Find(t->firstChild, key);
	if (p != nullptr)
		return p;
	return Find(t->nextSibling, key);
}
TreeNode* Parent(TreeNode* const t, TreeNode* p)
{
	if (t == nullptr || p == nullptr || p == t)
		return nullptr;

	TreeNode* q = t->firstChild;
	while (q != nullptr && q != p) {
		TreeNode* parent = Parent(q, p);
		if (parent != nullptr)
			return parent;
		q = q->nextSibling;
	}
	if (q != nullptr && q == p)
		return t;
	return nullptr;
}
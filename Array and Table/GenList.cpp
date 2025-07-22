#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "GenList.h"
using namespace std;

void InitGenList(GenList& gl)
{
	gl = nullptr;
}

static bool serve(char* sub, char* hsub)
{
	if (*sub == '\0' || strcmp(sub, "()") == 0) {
		hsub[0] = '\0';
		return true;
	}
	
	int n = strlen(sub);
	int i = 0, k = 0;
	char ch = sub[0];
	while (i < n && (ch != ',' || k != 0)) {
		if (ch == '(')
			k++;
		else if (ch == ')')
			k--;
		i++;
		ch = sub[i];
	}
	if (i < n) {
		sub[i] = '\0';
		strcpy(hsub, sub);
		strcpy(sub, sub + i + 1);
	}
	else if (k != 0)
		return false;
	else {
		strcpy(hsub, sub);
		sub[0] = '\0';
	}
	return true;
}
void CreateGenList(GenList& gl, const char* str)
{
	int n = strlen(str);
	//除去最外层括号
	char* sub = new(nothrow) char[n - 1];
	if (sub == nullptr)
		exit(-1);
	strncpy(sub, str + 1, n - 1);
	sub[n - 2] = '\0';
	//所有表头结点
	char* hsub = new(nothrow) char[n - 1];
	if (hsub == nullptr) {
		delete[] sub;
		exit(-1);
	}
	if (gl == nullptr) {
		gl = new(nothrow) GLNode;
		if (gl == nullptr) {
			delete[] sub, delete[] hsub;
			exit(-1);
		}
		gl->tag = HEAD;
		gl->hp = gl->tp = nullptr;
	}

	GLNode* p = gl;
	while (strlen(sub) != 0)
	{
		p = p->tp = new(nothrow) GLNode;
		if (p == nullptr) 
			exit(-1);
		p->hp = p->tp = nullptr;

		if (serve(sub, hsub)) {
			if (hsub[0] == '(') {
				p->tag = LIST;
				CreateGenList(p->hp, hsub);
			}
			else {
				p->tag = ATOM;
				p->atom = atoi(hsub);
			}
		}
	}
}
void ShowGenList(const GenList& gl)
{
	GLNode* p = gl->tp;
	cout << "(";
	while (p != nullptr) {
		if (p->tag == ATOM) {
			cout << p->atom;
			if (p->tp != nullptr)
				cout << ",";
			p = p->tp;
		}
		else if (p->tag == LIST) {
			ShowGenList(p->hp);
			if (p->tp != nullptr)
				cout << ",";
			p = p->tp;
		}
	}
	cout << ")";
}
void DestroyGenList(GenList& gl)
{
	if (gl->tp != nullptr)
		DestroyGenList(gl->tp);
	if (gl->tag == LIST)
		DestroyGenList(gl->hp);
	delete gl;
}

bool GenListEmpty(const GenList& gl)
{
	return gl->tp == nullptr;
}
int GenListLength(const GenList& gl)
{
	int length = 0;
	GLNode* p = gl->tp;
	while (p != nullptr) {
		length++;
		p = p->tp;
	}
	return length;
}
int GenListDepth(const GenList& gl)
{
	if (gl->tp == nullptr)
		return 0;
	GLNode* p = gl->tp;
	/*int max_depth = 1;
	while (p != nullptr)
	{
		if (p->tag == LIST) {
			max_depth++;
			p = p->hp;
		}
		p = p->tp;
	}
	return max_depth;*/
	int max_depth = 0, dep;
	while (p != nullptr) {
		if (p->tag == LIST) {
			dep = GenListDepth(p->hp);
			if (dep > max_depth)
				max_depth = dep;
		}
		p = p->tp;
	}
	return max_depth + 1;
}
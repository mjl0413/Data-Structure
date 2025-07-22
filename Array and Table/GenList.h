#pragma once

typedef int AtomType;

enum ElemTag {
	HEAD,
	ATOM,
	LIST
};
struct GLNode {
	ElemTag tag;
	union {
		AtomType atom;
		GLNode* hp;    //ͷָ�룬ָ���ӱ�
	};
	GLNode* tp;  //βָ��
};
typedef GLNode* GenList;

void InitGenList(GenList& gl);
void CreateGenList(GenList& gl, const char* str);
void ShowGenList(const GenList& gl);
void DestroyGenList(GenList& gl);

bool GenListEmpty(const GenList& gl);
int GenListLength(const GenList& gl);
int GenListDepth(const GenList& gl);
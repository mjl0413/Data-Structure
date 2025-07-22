#pragma once

//#define BISIC
typedef int ElemType;

#ifdef BISIC
struct ListNode {
	ElemType data;
	ListNode* next;
};
typedef ListNode* LinkList;

void InitList(LinkList& head);
void CreateList_back(LinkList& head);
void CreateList_front(LinkList& head);
void ShowList(const LinkList& head);

#else
struct Node {
	ElemType data;
	Node* next;
};
struct List {
	Node* first; //����ͷ
	Node* last;  //����β
	int size;    //�����ȣ�����ͷ���
};

void InitList(List& list);
void ClearList(List& list);
void DestroyList(List& list);

void push_back(List& list, ElemType x);
void push_front(List& list, ElemType x);
void pop_back(List& list);
void pop_front(List& list);
void show_list(const List& list);

/* ��С������� */
void insert_val(List& list, ElemType x);
void insert_pos(List& list, Node* pos, ElemType x);
Node* find(const List& list, ElemType key);
void delete_val(List& list, ElemType key);
/* ��С�������� */
void sort(List& list);
void reverse(List& list);

#endif
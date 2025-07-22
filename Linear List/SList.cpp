#include <iostream>
#include "SList.h"
using namespace std;

#ifdef BISIC
/* 不含头结点
void InitList(LinkList& head)
{
	head = nullptr;
}
void CreateList_back(LinkList& head)
{
	head = new(nothrow) ListNode;
	if (head == nullptr)
		exit(-1);
	head->data = 1;
	head->next = nullptr;

	LinkList p = head;
	for (int i = 2; i < 10; i++) {
		LinkList q = new(nothrow) ListNode;
		if (q == nullptr)
			exit(-1);
		q->data = i;
		q->next = nullptr;

		p->next = q;
		p = q;
	}
}
void CreateList_front(LinkList& head)
{
	head = new(nothrow) ListNode;
	if (head == nullptr)
		exit(-1);
	head->data = 1;
	head->next = nullptr;

	for (int i = 2; i < 10; i++) {
		LinkList p = new(nothrow) ListNode;
		if (p == nullptr)
			exit(-1);
		p->data = i;
		p->next = head;

		head = p;
	}
}
void ShowList(const LinkList& head)
{
	ListNode* p = head;
	while (p != nullptr) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
*/
void InitList(LinkList& head)
{
	head = new(nothrow) ListNode;
	if (head == nullptr)
		exit(-1);
	head->next = nullptr;
}
void CreateList_back(LinkList& head)
{
	LinkList p = head;
	for (int i = 1; i <= 10; i++) {
		p = p->next = new(nothrow) ListNode;
		if (p == nullptr)
			exit(-1);
		p->data = i;
		p->next = nullptr;
	}
}
void CreateList_front(LinkList& head)
{
	for (int i = 1; i <= 10; i++) {
		LinkList p = new(nothrow) ListNode;
		if (p == nullptr)
			exit(-1);
		p->data = i;
		p->next = head->next;
		head->next = p;
	}
}
void ShowList(const LinkList& head)
{
	ListNode* p = head->next;
	while (p != nullptr) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

#else
void InitList(List& list)
{
	list.first = list.last = new(nothrow) Node;
	if (list.first == nullptr)
		exit(-1);
	list.first->next = nullptr;
	list.size = 0;
}
void ClearList(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	while (p != nullptr) {
		Node* q = p;
		p = p->next;
		delete q;
	}
	list.last = list.first;
	list.size = 0;
}
void DestroyList(List& list)
{
	ClearList(list);
	delete list.first;
	list.first = list.last = nullptr;
}

void push_back(List& list, ElemType x)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		return;
	s->data = x;
	s->next = nullptr;

	list.last->next = s;
	list.last = s;
	list.size++;
}
void push_front(List& list, ElemType x)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		return;
	s->data = x;
	s->next = list.first->next;
	list.first->next = s;

	if (list.size == 0) 
		list.last = s;
	list.size++;
}
void pop_back(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first;
	while (p->next != list.last)
		p = p->next;
	delete list.last;
	list.last = p;
	list.last->next = nullptr;
	list.size--;
}
void pop_front(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	list.first->next = p->next;
	delete p;
	if (list.size == 1)
		list.last = list.first;
	list.size--;
}
void show_list(const List& list)
{
	Node* p = list.first->next;
	while (p != nullptr) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void insert_val(List& list, ElemType x)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		return;
	s->data = x;
	s->next = nullptr;

	Node* p = list.first;
	while (p->next != nullptr && p->next->data < x)
		p = p->next;
	if (p->next == nullptr)
		list.last = s;

	s->next = p->next;
	p->next = s;
	list.size++;
}
void insert_pos(List& list, Node* pos, ElemType x)
{
	Node* p = list.first;
	while (p->next != pos)
		p = p->next;
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		return;
	s->data = x;
	s->next = p->next;
	p->next = s;
	list.size++;
}
Node* find(const List& list, ElemType key)
{
	Node* p = list.first->next;
	while (p != nullptr && p->data != key)
		p = p->next;
	return p;
}
void delete_val(List& list, ElemType key)
{
	if (list.size == 0)
		return;

	Node* p = find(list, key);
	if (p == nullptr) {
		cout << "要删除的数据不存在." << endl;
		return;
	}

	if (p == list.last)
		pop_back(list);
	else {
		Node* q = p->next;
		p->data = q->data;
		p->next = q->next;
		delete q;
		list.size--;
	}
}
void sort(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* p = list.first->next;
	Node* q = p->next;
	list.last = p;
	list.last->next = nullptr;

	while (q != nullptr) {
		Node* s = q;
		q = q->next;

		p = list.first;
		while (p->next != nullptr && p->next->data < s->data)
			p = p->next;
		if (p->next == nullptr)
			list.last = s;
		s->next = p->next;
		p->next = s;
	}
}
void reverse(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* p = list.first->next;
	Node* q = p->next;
	list.last = p;
	list.last->next = nullptr;

	while (q != nullptr) {
		p = q;
		q = p->next;

		p->next = list.first->next;
		list.first->next = p;
    }
}

#endif
#include <iostream>
#include "DList.h"
using namespace std;

static Node* buy_node(ElemType x)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		exit(-1);
	s->data = x;
	s->next = s->prio = nullptr;
	return s;
}
void InitDList(List& list)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		exit(-1);
	list.first = list.last = s;
	list.last->next = nullptr;
	list.first->prio = nullptr;
	list.size = 0;
}
void ClearDList(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	while (p != nullptr) 
	{
		if (p == list.last) {
			list.last = list.first;
			list.last->next = nullptr;
		}
		else {
			p->next->prio = list.first;
			list.first->next = p->next;
		}
		delete p;
		p = list.first->next;
	}
	list.size = 0;
}
void DestroyDList(List& list)
{
	ClearDList(list);
	delete list.first;
	list.first = list.last = nullptr;
}

void D_push_back(List& list, ElemType x)
{
	Node* s = buy_node(x);
	s->prio = list.last;
	list.last->next = s;
	list.last = s;
	list.size++; 
}
void D_push_front(List& list, ElemType x)
{
	Node* s = buy_node(x);

	if (list.size == 0)
		s->prio = list.first;
	else {
		s->next = list.first->next;
		s->next->prio = s;
	}
	s->prio = list.first;
	list.first->next = s;
	list.size++;
}
void D_pop_back(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.last->prio;
	delete list.last;
	list.last = p;
	list.last->next = nullptr;
	list.size--;
}
void D_pop_front(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	if (p == list.last) {
		list.last = list.first;
		list.last->next = nullptr;
	}
	else {
		p->next->prio = list.first;
		list.first->next = p->next;
	}
	delete p;
	list.size--;
}
void D_show_list(const List& list)
{
	Node* p = list.first->next;
	while (p != nullptr) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void D_insert_val(List& list, ElemType x)
{
	Node* p = list.first;
	while (p->next != nullptr && p->next->data <= x)
		p = p->next;
	if (p->next == nullptr)
		D_push_back(list, x);
	else {
		Node* s = buy_node(x);
		s->next = p->next;
		s->prio = p;
		s->next->prio = s;
		p->next = s;
		list.size++;
	}
}
Node* D_find(const List& list, ElemType key)
{
	Node* p = list.first->next;
	while (p != nullptr && p->data != key)
		p = p->next;
	return p;
}
void D_delete_val(List& list, ElemType key)
{
	if (list.size == 0)
		return;
	Node* p = D_find(list, key);
	if (p == nullptr) {
		cout << "要删除的值不存在." << endl;
		return;
	}

	if (p == list.last) {
		list.last = p->prio;
		list.last->next = nullptr;
	}
	else {
		p->prio->next = p->next;
		p->next->prio = p->prio;
	}
	delete p;
	list.size--;
}
void D_sort(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* s = list.first->next;
	Node* q = s->next;
	list.last = s;
	list.last->next = nullptr;

	while (q != nullptr) {
		s = q;
		q = q->next;
		Node* p = list.first;
		while (p->next != nullptr && p->next->data < s->data)
			p = p->next;

		if (p->next == nullptr) {
			s->next = nullptr;
			s->prio = list.last;
			list.last->next = s;
			list.last = s;
		}
		else {
			s->next = p->next;
			s->prio = p;
			s->next->prio = s;
			p->next = s;
		}

	}
}
void D_reverse(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* p = list.first->next;
	Node* q = p->next;
	list.last = p;
	list.last->next = nullptr;

	while (q != nullptr) {
		p = q;
		q = q->next;

		p->next = list.first->next;
		p->next->prio = p;
		p->prio = list.first;
		list.first->next = p;
	}
}
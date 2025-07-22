#include <iostream>
#include "SCList.h"
using namespace std;

static Node* buy_node(ElemType x)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		exit(-1);
	s->data = x;
	s->next = nullptr;
	return s;
}
void InitSCList(List& list)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		return;
	list.first = list.last = s;
	list.last->next = list.first;
	list.size = 0;
}
void ClearSCList(List& list)
{
	Node* p = list.first->next;
	while (p != list.first) {
		list.first->next = p->next;
		delete p;
		p = list.first->next;
	}
	list.last = list.first;
	list.last->next = list.first;
	list.size = 0;
}
void DestroySCList(List& list)
{
	ClearSCList(list);
	delete list.first;
	list.first = list.last = nullptr;
}

void SC_push_back(List& list, ElemType x)
{
	Node* s = buy_node(x);
	list.last->next = s;
	list.last = s;
	list.last->next = list.first;
	list.size++;
}
void SC_push_front(List& list, ElemType x)
{
	Node* s = buy_node(x);
	s->next = list.first->next;
	list.first->next = s;
	if (list.size == 0)
		list.last = s;
	list.size++;
}
void SC_pop_back(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first;
	while (p->next != list.last)
		p = p->next;
	delete p->next;
	list.last = p;
	list.last->next = list.first;
	list.size--;

}
void SC_pop_front(List& list)
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
void SC_show_list(const List& list)
{
	Node* p = list.first->next;
	while (p != list.first) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void SC_insert_val(List& list, ElemType x)
{
	Node* p = list.first;
	while (p->next != list.first && p->next->data < x)
		p = p->next;
	if (p->next == list.first && p->data <= x)
		SC_push_back(list, x);
	else {
		Node* s = buy_node(x);
		s->next = p->next;
		p->next = s;
		list.size++;
	}
}
Node* SC_find(const List& list, ElemType key)
{
	if (list.size == 0)
		return nullptr;
	Node* p = list.first->next;
	while (p != list.first && p->data != key)
		p = p->next;
	if (p == list.first)
		return nullptr;
	return p;
}
void SC_delete_val(List& list, ElemType key)
{
	if (list.size == 0)
		return;
	Node* p = SC_find(list, key);
	if (p == nullptr) {
		cout << "要删除的数据不存在." << endl;
		return;
	}
	if (p == list.last)
		SC_pop_back(list);
	else {
		Node* q = p->next;
		p->data = q->data;
		p->next = q->next;
		delete q;
		if (p->next == list.first)
			list.last = p;
		list.size--;
	}
}
void SC_sort(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* s = list.first->next;
	Node* q = s->next;
	list.last->next = nullptr;
	list.last = s;
	list.last->next = list.first;

	while (q != nullptr) {
		s = q;
		q = q->next;

		Node* p = list.first;
		while (p->next != list.first && p->next->data < s->data)
			p = p->next;
		if (p->next == list.first && p->data < s->data) {
			s->next = list.last->next;
			list.last->next = s;
			list.last = s;
		}
		else {
			s->next = p->next;
			p->next = s;
		}
	}
}
void SC_reverse(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* p = list.first->next;
	Node* q = p->next;
	list.last->next = nullptr;
	list.last = p;
	list.last->next = list.first;

	while (q != nullptr) {
		p = q;
		q = q->next;

		p->next = list.first->next;
		list.first->next = p;
	}
}
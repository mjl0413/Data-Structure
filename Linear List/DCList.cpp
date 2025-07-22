#include <iostream>
#include "DCList.h"
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
void InitDCList(List& list)
{
	Node* s = new(nothrow) Node;
	if (s == nullptr)
		exit(-1);
	list.first = list.last = s;
	list.last->next = list.first;
	list.first->prio = list.last;
	list.size = 0;
}
void ClearDCList(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	while (p != list.first) {
		p->next->prio = list.first;
		list.first->next = p->next;
		delete p;
		p = list.first->next;
	}
	list.last = list.first;
	list.size = 0;
}
void DestroyDCList(List& list)
{
	ClearDCList(list);
	delete list.first;
	list.first = list.last = nullptr;
}

void DC_push_back(List& list, ElemType x)
{
	Node* s = buy_node(x);
	s->next = list.last->next;
	s->prio = list.last;
	s->next->prio = s;
	list.last->next = s;

	list.last = s;
	list.size++;
}
void DC_push_front(List& list, ElemType x)
{
	Node* s = buy_node(x);
	s->next = list.first->next;
	s->next->prio = s;
	s->prio = list.first;
	list.first->next = s;

	if (list.size == 0)
		list.last = s;
	list.size++;
}
void DC_pop_back(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.last;
	list.last = list.last->prio;

	p->next->prio = p->prio;
	p->prio->next = p->next;
	delete p;
	list.size--;
}
void DC_pop_front(List& list)
{
	if (list.size == 0)
		return;
	Node* p = list.first->next;
	p->next->prio = p->prio;
	p->prio->next = p->next;

	if (list.size == 1)
		list.last = list.first;
	list.size--;
}
void DC_show_list(const List& list)
{
	Node* p = list.first->next;
	while (p != list.first) {
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void DC_insert_val(List& list, ElemType x)
{
	Node* p = list.first;
	while (p->next != list.last && p->next->data <= x)
		p = p->next;
	if (p->next == list.last && p->next->data <= x)
		DC_push_back(list, x);
	else {
		Node* s = buy_node(x);
		s->next = p->next;
		s->next->prio = s;
		s->prio = p;
		p->next = s;
		list.size++;
	}
}
Node* DC_find(const List& list, ElemType key)
{
	Node* p = list.first->next;
	while (p != list.first && p->data != key)
		p = p->next;
	if (p == list.first)
		return nullptr;
	return p;
}
void DC_delete_val(List& list, ElemType key)
{
	if (list.size == 0)
		return;
	Node* p = DC_find(list, key);
	if (p == nullptr) {
		cout << "要删除的值不存在." << endl;
		return;
	}

	if (p == list.last)
		DC_pop_back(list);
	else {
		p->next->prio = p->prio;
		p->prio->next = p->next;
		delete p;
		list.size--;
	}
}
void DC_sort(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* s = list.first->next;
	Node* q = s->next;
	list.last->next = nullptr;
	list.last = s;
	list.last->next = list.first;
	list.first->prio = list.last;

	while (q != nullptr)
	{
		s = q;
		q = q->next;

		Node* p = list.first;
		while (p->next != list.last && p->next->data <= s->data)
			p = p->next;
		if (p->next == list.last && p->next->data <= s->data) {
			s->next = list.last->next;
			s->next->prio = s;
			s->prio = list.last;
			list.last->next = s;
			list.last = s;
		}
		else {
			s->next = p->next;
			s->next->prio = s;
			s->prio = p;
			p->next = s;
		}
	}
}
void DC_reverse(List& list)
{
	if (list.size == 0 || list.size == 1)
		return;
	Node* p = list.first->next;
	Node* q = p->next;
	list.last->next = nullptr;
	list.last = p;
	list.last->next = list.first;
	list.first->prio = list.last;

	while (q != nullptr)
	{
		p = q;
		q = q->next;

		p->next = list.first->next;
		p->next->prio = p;
		p->prio = list.first;
		list.first->next = p;
	}
}
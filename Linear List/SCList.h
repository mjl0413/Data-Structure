#pragma once

typedef int ElemType;

struct Node {
	ElemType data;
	Node* next;
};
struct List {
	Node* first;
	Node* last;
	int size;
};

void InitSCList(List& list);
void ClearSCList(List& list);
void DestroySCList(List& list);

void SC_push_back(List& list, ElemType x);
void SC_push_front(List& list, ElemType x);
void SC_pop_back(List& list);
void SC_pop_front(List& list);
void SC_show_list(const List& list);

/* 从小到大插入 */
void SC_insert_val(List& list, ElemType x);
Node* SC_find(const List& list, ElemType key);
void SC_delete_val(List& list, ElemType key);
/* 从小到大排序 */
void SC_sort(List& list);
void SC_reverse(List& list);
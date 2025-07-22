#pragma once

typedef int ElemType;

struct Node {
	ElemType data;
	Node* prio;
	Node* next;
};
struct List {
	Node* first;
	Node* last;
	int size;
};

void InitDCList(List& list);
void ClearDCList(List& list);
void DestroyDCList(List& list);

void DC_push_back(List& list, ElemType x);
void DC_push_front(List& list, ElemType x);
void DC_pop_back(List& list);
void DC_pop_front(List& list);
void DC_show_list(const List& list);

/* 从小到大插入 */
void DC_insert_val(List& list, ElemType x);
Node* DC_find(const List& list, ElemType key);
void DC_delete_val(List& list, ElemType key);
/* 从小到大排序 */
void DC_sort(List& list);
void DC_reverse(List& list);
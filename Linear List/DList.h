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

void InitDList(List& list);
void ClearDList(List& list);
void DestroyDList(List& list);

void D_push_back(List& list, ElemType x);
void D_push_front(List& list, ElemType x);
void D_pop_back(List& list);
void D_pop_front(List& list);
void D_show_list(const List& list);

/* 从小到大插入 */
void D_insert_val(List& list, ElemType x);
Node* D_find(const List& list, ElemType key);
void D_delete_val(List& list, ElemType key);
/* 从小到大排序 */
void D_sort(List& list);
void D_reverse(List& list);
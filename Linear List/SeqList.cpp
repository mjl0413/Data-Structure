#include <iostream>
#include "SeqList.h"
using namespace std;

void InitSeqList(SeqList& list)
{
	list.base = new(nothrow) ElemType[SEQLIST_SIZE];
	if (list.base == nullptr)
		exit(-1);
	list.capacity = SEQLIST_SIZE;
	list.size = 0;
}
void DestroyList(SeqList& list)
{
	delete[] list.base;
	list.base = nullptr;
	list.capacity = 0;
	list.size = 0;
}
void ClearList(SeqList& list)
{
	list.size = 0;
}
bool IncList(SeqList& list)
{
	ElemType* newbase = (ElemType*)realloc(list.base, sizeof(ElemType) * (list.capacity + INC_SIZE));
	if (newbase == nullptr) {
		cout << "增配空间失败." << endl;
		return false;
	}
	list.base = newbase;
	list.capacity += INC_SIZE;
	return true;
}
void MergeList(SeqList& list, const SeqList& la, const SeqList& lb)
{
	list.capacity = la.size + lb.size;
	list.base = new(nothrow) ElemType[list.capacity];
	if (list.base == nullptr)
		exit(-1);

	int i = 0, ia = 0, ib = 0;
	while (ia < la.size && ib < lb.size) {
		if (la.base[ia] < lb.base[ib])
			list.base[i++] = la.base[ia++];
		else
			list.base[i++] = lb.base[ib++];
	}
	while (ia < la.size)
		list.base[i++] = la.base[ia++];
	while (ib < lb.size)
		list.base[i++] = lb.base[ib++];
	list.size = la.size + lb.size;
}

void push_back(SeqList& list, ElemType x)
{
	if (list.size >= list.capacity && !IncList(list)) {
		cout << "顺序表已满，无法尾插." << endl;
		return;
	}
	list.base[list.size] = x;
	list.size++;
}
void push_front(SeqList& list, ElemType x)
{
	if (list.size >= list.capacity && !IncList(list)) {
		cout << "顺序表已满，无法头插." << endl;
		return;
	}
	for (int i = list.size; i > 0; i--)
		list.base[i] = list.base[i - 1];
	list.base[0] = x;
	list.size++;
}
void insert_pos(SeqList& list, int pos, ElemType x)
{

	if (pos<0 || pos>list.size) {
		cout << "插入位置非法." << endl;
		return;
	}
	if (list.size >= list.capacity && !IncList(list)) {
		cout << "顺序表已满，无法插入." << endl;
		return;
	}
	for (int i = list.size; i > pos; i--)
		list.base[i] = list.base[i - 1];
	list.base[pos] = x;
	list.size++;
}
void pop_back(SeqList& list)
{
	if (list.size == 0) {
		cout << "顺序表为空，无法尾删." << endl;
		return;
	}
	list.size--;
}
void pop_front(SeqList& list)
{
	if (list.size == 0) {
		cout << "顺序表为空，无法头删." << endl;
		return;
	}
	for (int i = 0; i < list.size - 1; i++)
		list.base[i] = list.base[i + 1];
	list.size--;
}
void delete_pos(SeqList& list, int pos)
{

	if (pos < 0 || pos >= list.size) {
		cout << "删除位置非法." << endl;
		return;
	}
	if (list.size == 0) {
		cout << "顺序表为空，无法删除." << endl;
		return;
	}

	for (int i = pos; i < list.size - 1; i++)
		list.base[i] = list.base[i + 1];
	list.size--;
}
void show_list(const SeqList& list)
{
	for (int i = 0; i < list.size; i++)
		cout << list.base[i] << " ";
	cout << endl;
}

int Seq_find(const SeqList& list, ElemType key)
{
	for (int i = 0; i < list.size; i++)
		if (list.base[i] == key)
			return i;
	return -1;
}
void delete_val(SeqList& list, ElemType key)
{
	int pos = Seq_find(list, key);
	if (pos == -1) {
		cout << "要删除的值不存在." << endl;
		return;
	}
	delete_pos(list, pos);
}
void sort(SeqList& list)
{
	for (int i = 0; i < list.size - 1; i++)
		for (int j = 0; j < list.size - i - 1; j++)
			if (list.base[j] > list.base[j + 1]) {
				ElemType temp = list.base[j];
				list.base[j] = list.base[j + 1];
				list.base[j + 1] = temp;
			}
}
void reverse(SeqList& list)
{
	if (list.size == 0 || list.size == 1)
		return;

	int low = 0, high = list.size - 1;
	ElemType temp;
	while (high > low) {
		temp = list.base[low];
		list.base[low] = list.base[high];
		list.base[high] = temp;

		low++, high--;
	}
}

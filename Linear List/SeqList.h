#pragma once

typedef int ElemType;

#define SEQLIST_SIZE  8
#define INC_SIZE      3
struct SeqList {
	ElemType* base;  //头指针
	int capacity;    //总容量
	int size;        //当前大小
};

void InitSeqList(SeqList& list);
void DestroyList(SeqList& list);
void ClearList(SeqList& list);
/* 动态增加 */
bool IncList(SeqList& list);
/* 合并 */
void MergeList(SeqList& list, const SeqList& la, const SeqList& lb);

/* 尾插法 */
void push_back(SeqList& list, ElemType x);
/* 头插法 */
void push_front(SeqList& list, ElemType x);
/* 某位置插入 */
void insert_pos(SeqList& list, int pos, ElemType x);
/* 尾删法 */
void pop_back(SeqList& list);
/* 头删法 */
void pop_front(SeqList& list);
/* 按位置删除 */
void delete_pos(SeqList& list, int pos);
/* 打印 */
void show_list(const SeqList& list);

/* 查找 */
int Seq_find(const SeqList& list, ElemType key);
/* 按值删除 */
void delete_val(SeqList& list, ElemType key);
/* 排序 */
void sort(SeqList& list);
/* 翻转 */
void reverse(SeqList& list);
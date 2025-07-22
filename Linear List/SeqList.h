#pragma once

typedef int ElemType;

#define SEQLIST_SIZE  8
#define INC_SIZE      3
struct SeqList {
	ElemType* base;  //ͷָ��
	int capacity;    //������
	int size;        //��ǰ��С
};

void InitSeqList(SeqList& list);
void DestroyList(SeqList& list);
void ClearList(SeqList& list);
/* ��̬���� */
bool IncList(SeqList& list);
/* �ϲ� */
void MergeList(SeqList& list, const SeqList& la, const SeqList& lb);

/* β�巨 */
void push_back(SeqList& list, ElemType x);
/* ͷ�巨 */
void push_front(SeqList& list, ElemType x);
/* ĳλ�ò��� */
void insert_pos(SeqList& list, int pos, ElemType x);
/* βɾ�� */
void pop_back(SeqList& list);
/* ͷɾ�� */
void pop_front(SeqList& list);
/* ��λ��ɾ�� */
void delete_pos(SeqList& list, int pos);
/* ��ӡ */
void show_list(const SeqList& list);

/* ���� */
int Seq_find(const SeqList& list, ElemType key);
/* ��ֵɾ�� */
void delete_val(SeqList& list, ElemType key);
/* ���� */
void sort(SeqList& list);
/* ��ת */
void reverse(SeqList& list);
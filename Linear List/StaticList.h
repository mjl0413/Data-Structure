#pragma once

typedef char ElemType;

#define MAX_SIZE  20
typedef struct {
	ElemType data;
	int cur;
}ListNode, StaticList[MAX_SIZE];

int new_SL(StaticList& space);
void delete_SL(StaticList& space, int k);

void InitSList(StaticList& space);
/* 头插法 */
void Insert(StaticList& space, ElemType x);
/* 头删法 */
void Delete(StaticList& space);
void ShowSList(const StaticList& space);
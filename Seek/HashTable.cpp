#include <iostream>
#include "Stack.h"
#include "HashTable.h"
using namespace std;

void InitHashTable(HashTable& ht)
{
	for (int i = 0; i < P; i++)
		ht[i] = nullptr;
}
void DestroyHashTable(HashTable& ht)
{
	LinkStack st;
	InitStack(st);
	for (int i = 0; i < P; i++) {
		HashNode* p = ht[i];
		while (p != nullptr) {
			Push(st, p);
			p = p->link;
		}

	}
}

static int Hash(ElemType key)
{
	return key % P;
}
void InsertHashTable(HashTable& ht, ElemType x)
{
	int index = Hash(x);
	HashNode* s = new(nothrow) HashNode;
	if (s == nullptr)
		exit(-1);
	s->data = x;
	
	s->link = ht[index];
	ht[index] = s;
}
bool RemoveHashTable(HashTable& ht, ElemType key)
{
	HashNode* p = SearchHashTable(ht, key);
	if (p == nullptr)
		return false;

	int index = Hash(key);
	HashNode* q = ht[index];
	if (q == p) 
		ht[index] = p->link;
	else {
		while (q->link != p)
			q = q->link;
		q->link = p->link;
	}
	delete p;
	return true;
}
void ShowHashTable(const HashTable& ht)
{
	for (int i = 0; i < P; i++)
	{
		cout << i << " : ";
		HashNode* p = ht[i];
		while (p != nullptr) {
			cout << p->data << "-->";
			p = p->link;
		}
		cout << "NULL" << endl;
	}
}

HashNode* SearchHashTable(const HashTable& ht, ElemType key)
{
	int index = Hash(key);
	HashNode* p = ht[index];
	while (p != nullptr && key != p->data)
		p = p->link;
	return p;
}
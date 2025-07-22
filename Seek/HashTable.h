#pragma once

typedef int ElemType;

#define P   13

struct HashNode {
	ElemType data;
	HashNode* link;
};
typedef HashNode* HashTable[P];

void InitHashTable(HashTable& ht);
void DestroyHashTable(HashTable& ht);

void InsertHashTable(HashTable& ht, ElemType x);
bool RemoveHashTable(HashTable& ht, ElemType key);
void ShowHashTable(const HashTable& ht);

HashNode* SearchHashTable(const HashTable& ht, ElemType key);
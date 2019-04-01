#pragma once
typedef struct DNode
{
	int data;
	struct DNode *next;
	struct DNode *prio;
}DNode, *DList;
void InitList(DList plist);
bool Insert_head(DList plist, int val);
bool Insert_tail(DList plist, int val);
DNode *Search_pri(DList plist, int key);
bool Delete(DList plist, int key);
bool IsEmpty(DList plist);
void Destroy(DList plist);
int GetLength(DList plist);
void Show(DList plist);

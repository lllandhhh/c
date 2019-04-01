#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;
void InitList(List plist);//初始化单链表

bool Insert_head(List plist,int val);//头插法

bool Insert_tail(List plist,int val);//尾插法

bool Insert_pos(List plist,int pos,int val);//pos 位置插入

Node *Search_pre(List plist,int key);//查找 key 的前驱

bool Delete(List plist,int key);//删除 key 这个结点

bool IsEmpty(List plist);//是否为空

void Destroy(List plist);//摧毁函数（如果有动态开辟内存）

int GetLength(List plist);//得到单链表的长度

void Show(List plist);//打印单链表
void nizhi(List plist);

Node *ListK(List plist, int k);//找出倒数第K个节点
void dlist(List plist, int k);//删除 倒数第K个节点
bool lscut(List plist1, List plist);//判断两个单链表 是否相交
Node* MergeList(List plist1, List plist2);
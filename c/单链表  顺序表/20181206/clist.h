#pragma once
typedef struct CNode
{
	int data;
	struct CNode *next;
}CNode, *CList;
void InitList(CList plist);//初始化
bool Insert_head(CList plist, int val);//头插法
bool Insert_tail(CList plist, int val);//尾插法
CNode *Search_pri(CList plist, int key);//查找前驱
bool Delete(CList plist, int key);//删除
bool IsEmpty(CList plist);//是否为空
void Destroy(CList plist);//摧毁
int GetLength(CList plist);//得到长度
void Show(CList plist);//显示函数

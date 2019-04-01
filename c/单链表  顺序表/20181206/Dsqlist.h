#pragma once
#define INIT_SIZE 10
typedef struct DSqlist
{
	int *elem;//存储数据的内存
	int usedsize;//有效数据个数
	int size;//总单元数
}DSqlist,*PDSqlist;
void InitList(PDSqlist psq);

bool Insert(PDSqlist psq,int pos,int val);

int Search(PDSqlist Psq,int pos,int key);//查找 key 值

bool DeletePos(PDSqlist Psq,int pos,int *rtv);//删除 pos 位置的值

bool Delete(PDSqlist Psq,int pos,int key);//删除一个 key 值

void Clear(PDSqlist psq);

void Destroy(PDSqlist psq);

void Show(PDSqlist psq);
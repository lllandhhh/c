#pragma once//预防头文件重复引用
#define SIZE 10
typedef  struct Splist
{
	int elem[SIZE];
	int usedsize;
}sqlist, *PSqlist;
void InitSqlist(PSqlist Psq);//初始化

bool Insert(PSqlist Psq, int pos, int val);//在 pos 位置插入 val 值

int Search(PSqlist Psq, int pos, int key);//查找 key 值

bool DeletePos(PSqlist Psq, int pos, int *rtv);//删除 pos 位置的值

bool Delete(PSqlist Psq, int pos, int key);//删除一个 key 值

bool GetElem(PSqlist Psq, int pos, int *rtv);

int GetLength(PSqlist Psq);

void Clear(PSqlist Psq);

void Destory(PSqlist Psq);

void Show(PSqlist Psq);


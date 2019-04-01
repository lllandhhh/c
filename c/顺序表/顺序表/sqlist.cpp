#include<stdio.h>
#include "sqlist.h"
#include<assert.h>
void InitSqlist(PSqlist Psq)//初始化形参是指针类型
{
	Psq->usedsize = 0;//指针类的必须要用->
}
static bool isFull(PSqlist psq)//判满
{
	if (10 == psq->usedsize)return false;
	else return true;
}
bool Insert(PSqlist Psq, int pos, int val)//在 pos 位置插入 val 值  顺序表输入数据前驱位置必须合法
{
	assert(Psq != NULL);
	if (pos<0 || pos>Psq->usedsize)return false;
	if (pos != NULL)
	{
		for (int i = Psq->usedsize-1;i >=pos;i--)
		{
			Psq->elem[i+1] = Psq->elem[i];
		}
		Psq->elem[pos] = val;
		Psq->usedsize++;
		return true;
		//pos位和以后向后移一位
	}
	else Psq->elem[pos] = val;
}
int Search(PSqlist Psq, int pos, int key)//从pos位置查找 key 值
{
	if (pos<0 || pos>=Psq->usedsize)return false;
	if(key<0||key>Psq->usedsize)
	{
		return -1;
	}

		for (int i = pos;i < Psq->usedsize;i++)
		{
			if (Psq->elem[i] == key)return 1;
		}
}

bool DeletePos(PSqlist Psq, int pos, int *rtv)//删除 pos 位置的值
{
	if (pos<0 || pos>Psq->usedsize)return false;
	if(rtv!=NULL)
	{
		*rtv = Psq->elem[pos];
	}
	
	for (int i = pos;i <Psq->usedsize-1;i++)
	{
		Psq->elem[i] = Psq->elem[i+1];
	}
	Psq->usedsize--;
	return false;
}
bool Delete(PSqlist Psq, int pos, int key)//删除一个 key 值
{}
bool GetElem(PSqlist Psq, int pos, int *rtv)//得到pos位置的值
{
	*rtv= Psq->elem[pos];
}
int GetLength(PSqlist Psq);

void Clear(PSqlist Psq);

void Destory(PSqlist Psq);

void Show(PSqlist Psq)//打印顺序表
{
	for (int i = 0;i < Psq->usedsize;i++)
	{
		printf("%d", Psq->elem[i]);
	}
}


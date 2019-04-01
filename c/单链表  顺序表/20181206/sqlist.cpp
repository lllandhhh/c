#include<stdio.h>
#include"sqlist.h"
#include<assert.h>

void InitSqlist(PSqlist Psq)//初始化
{
	assert(Psq != NULL);
	if(Psq == NULL)
	{
		return;
	}
	Psq->usedsize = 0;
}

static bool isFull(PSqlist Psq) 
{
	return Psq->usedsize == SIZE;
}

bool Insert(PSqlist Psq,int pos ,int val)//在 pos 位置插入 val 值
{
	assert(Psq != NULL);
	if(pos < 0 || pos > Psq->usedsize || isFull(Psq))
	{
		return false;
	}
	//挪数据
	for(int i = Psq->usedsize-1;i >= pos;i--)
	{
		Psq->elem[i+1] = Psq->elem[i];
	}
	Psq->elem[pos] = val;
	Psq->usedsize++;
	return true;
}
//从pos位置开始查找 key 值==>第一次出现==》返回下标  -1
static bool isEmpty(PSqlist Psq) 
{
	return Psq->usedsize == 0;
}
int Search(PSqlist Psq,int pos,int key)
{
	if(pos < 0 || pos >= Psq->usedsize || isEmpty(Psq))
	{
		return -1;
	}
	for(int i = pos;i < Psq->usedsize;i++)
	{
		if(Psq->elem[i] == key)
		{
			return i;
		}
	}
	return -1;
}

bool DeletePos(PSqlist Psq,int pos,int *rtv)//删除 pos 位置的值
{
	if(pos < 0 || pos >= Psq->usedsize || isEmpty(Psq))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = Psq->elem[pos];
	}
	for(int i = pos;i < Psq->usedsize-1;i++)
	{
		Psq->elem[i] = Psq->elem[i+1];
	}
	Psq->usedsize--;
	return true;
}
//删除一个 key 值
bool Delete(PSqlist Psq,int pos,int key)
{
	int index = Search(Psq,pos,key);
	if(index == -1)
	{
		return false;
	}
	return DeletePos(Psq,index,NULL);
}
//得到pos位置的值
bool GetElem(PSqlist Psq,int pos,int *rtv)
{
	if(pos < 0 || pos >= Psq->usedsize || isEmpty(Psq))
	{
		return false;
	}
	*rtv = Psq->elem[pos];
	return true;
}

int GetLength(PSqlist Psq)
{
	return Psq->usedsize;
}

void Clear(PSqlist Psq)
{
	Psq->usedsize = 0;
}

void Destory(PSqlist Psq);

void Show(PSqlist Psq)
{
	for (int i = 0; i < Psq->usedsize; i++)
	{
		printf("%d ",Psq->elem[i]);
	}
	printf("\n");
}
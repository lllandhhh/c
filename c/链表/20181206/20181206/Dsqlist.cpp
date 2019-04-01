#include"Dsqlist.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
void InitList(PDSqlist psq)
{
	assert(psq != NULL);
	psq->elem = (int *)malloc(sizeof(int) * INIT_SIZE);
	assert(psq->elem!= NULL);
	psq->usedsize = 0;
	psq->size = INIT_SIZE;
}
static bool isFull(PDSqlist psq)
{
	if(psq->usedsize == psq->size)
	{
		return true;
	}
	return false;
}
static void Inc(PDSqlist psq)
{
	int *p = (int *)realloc(psq->elem,psq->size*sizeof(int)*2);
	if(p != NULL)
	{
		psq->elem = p;
	}
	psq->size *= 2;
}
bool Insert(PDSqlist psq,int pos,int val)
{
	if(isFull(psq))
	{
		Inc(psq);
	}
	for(int i = psq->usedsize-1;i >= pos;i--)
	{
		psq->elem[i+1] = psq->elem[i];
	}
	psq->elem[pos] = val;
	psq->usedsize++;
	return true;
}
static bool isEmpty(PDSqlist Psq) 
{
	return Psq->usedsize == 0;
}
int Search(PDSqlist Psq,int pos,int key)//查找 key 值
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

bool DeletePos(PDSqlist Psq,int pos,int *rtv)//删除 pos 位置的值
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

bool Delete(PDSqlist Psq,int pos,int key)//删除一个 key 值
{
	int index = Search(Psq,pos,key);
	if(index == -1)
	{
		return false;
	}
	return DeletePos(Psq,index,NULL);
}

void Clear(PDSqlist psq)
{
	psq->usedsize = 0;
	//psq->size = 0;
}

void Destroy(PDSqlist psq)
{
	free(psq->elem);
	psq->elem = NULL;
	psq->usedsize = 0;
	psq->size = 0;
}

void Show(PDSqlist psq)
{
	for (int i = 0; i < psq->usedsize; i++)
	{
		printf("%d ",psq->elem[i]);
	}
	printf("\n");
}
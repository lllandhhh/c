#include<stdio.h>
#include"sqlist.h"
#include<assert.h>

void InitSqlist(PSqlist Psq)//��ʼ��
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

bool Insert(PSqlist Psq,int pos ,int val)//�� pos λ�ò��� val ֵ
{
	assert(Psq != NULL);
	if(pos < 0 || pos > Psq->usedsize || isFull(Psq))
	{
		return false;
	}
	//Ų����
	for(int i = Psq->usedsize-1;i >= pos;i--)
	{
		Psq->elem[i+1] = Psq->elem[i];
	}
	Psq->elem[pos] = val;
	Psq->usedsize++;
	return true;
}
//��posλ�ÿ�ʼ���� key ֵ==>��һ�γ���==�������±�  -1
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

bool DeletePos(PSqlist Psq,int pos,int *rtv)//ɾ�� pos λ�õ�ֵ
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
//ɾ��һ�� key ֵ
bool Delete(PSqlist Psq,int pos,int key)
{
	int index = Search(Psq,pos,key);
	if(index == -1)
	{
		return false;
	}
	return DeletePos(Psq,index,NULL);
}
//�õ�posλ�õ�ֵ
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
#include<stdio.h>
#include "sqlist.h"
#include<assert.h>
void InitSqlist(PSqlist Psq)//��ʼ���β���ָ������
{
	Psq->usedsize = 0;//ָ����ı���Ҫ��->
}
static bool isFull(PSqlist psq)//����
{
	if (10 == psq->usedsize)return false;
	else return true;
}
bool Insert(PSqlist Psq, int pos, int val)//�� pos λ�ò��� val ֵ  ˳�����������ǰ��λ�ñ���Ϸ�
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
		//posλ���Ժ������һλ
	}
	else Psq->elem[pos] = val;
}
int Search(PSqlist Psq, int pos, int key)//��posλ�ò��� key ֵ
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

bool DeletePos(PSqlist Psq, int pos, int *rtv)//ɾ�� pos λ�õ�ֵ
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
bool Delete(PSqlist Psq, int pos, int key)//ɾ��һ�� key ֵ
{}
bool GetElem(PSqlist Psq, int pos, int *rtv)//�õ�posλ�õ�ֵ
{
	*rtv= Psq->elem[pos];
}
int GetLength(PSqlist Psq);

void Clear(PSqlist Psq);

void Destory(PSqlist Psq);

void Show(PSqlist Psq)//��ӡ˳���
{
	for (int i = 0;i < Psq->usedsize;i++)
	{
		printf("%d", Psq->elem[i]);
	}
}


#include<stdio.h>
#include"dsqlist.h"
#include<stdlib.h>
#include<assert.h>
void InitList(PDSqlist psq)
{
	assert(psq);
	psq->elem = (int *)malloc(sizeof(int)*in_SIZE);
	assert(psq->elem);
	psq->usedsize=0;
	 psq->size=0;
}
static bool isFull(PDSqlist psq)//����
{
	if (psq->size == psq->usedsize)return false;
	else return true;
}
static void Inc(PDSqlist psq)//����
{
	psq->elem = (int *)realloc(psq->elem,sizeof(int)*in_SIZE*2);
	psq->size *= 2;
}
bool Insert(PDSqlist psq, int pos, int val);

int Search(PDSqlist Psq, int pos, int key);//���� key ֵ

bool DeletePos(PDSqlist Psq, int pos, int *rtv);//ɾ�� pos λ�õ�ֵ

bool Delete(PDSqlist Psq, int pos, int key);//ɾ��һ�� key ֵ

void Clear(PDSqlist psq)
{
	free(psq->elem);
	psq->elem = NULL;

}
void Destroy(PDSqlist psq);

void Show(PDSqlist psq);


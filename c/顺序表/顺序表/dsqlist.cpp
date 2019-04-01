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
static bool isFull(PDSqlist psq)//判满
{
	if (psq->size == psq->usedsize)return false;
	else return true;
}
static void Inc(PDSqlist psq)//扩容
{
	psq->elem = (int *)realloc(psq->elem,sizeof(int)*in_SIZE*2);
	psq->size *= 2;
}
bool Insert(PDSqlist psq, int pos, int val);

int Search(PDSqlist Psq, int pos, int key);//查找 key 值

bool DeletePos(PDSqlist Psq, int pos, int *rtv);//删除 pos 位置的值

bool Delete(PDSqlist Psq, int pos, int key);//删除一个 key 值

void Clear(PDSqlist psq)
{
	free(psq->elem);
	psq->elem = NULL;

}
void Destroy(PDSqlist psq);

void Show(PDSqlist psq);


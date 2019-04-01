#include"Lqueue.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
����ջʵ��һ������
��������ʵ��һ��ջ
*/
void InitQueueL(QueueList queue)
{
	assert(queue !=NULL);
	queue->last = NULL;
	queue->front = NULL;
}
static Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
bool Push(QueueList queue,int val)
{
	Node *pGet = GetNode(val);
	if(queue->last == NULL)//��һ�β���
	{
		queue->front = pGet;
	}
	else
	{
		queue->last->next = pGet;
	}
	queue->last = pGet;
	return true;
}

bool Pop(QueueList queue,int *rtv)
{
	if(IsEmpty(queue))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = queue->front->data;
	}
	Node *pDel = queue->front;
	queue->front = pDel->next;
	if(queue->front == NULL)
	{
		queue->last = NULL;
	}
	free(pDel);
	pDel = NULL;
	return true;
}

void Show(QueueList queue);

int GetLength(QueueList queue);

bool IsEmpty(QueueList queue)
{
	if(queue->front == NULL || queue->last == NULL)
	{
		return true;
	}
	return false;
}

void Clear(QueueList queue);

void Destroy(QueueList queue);
#include"Sqqueue.h"
#include<stdio.h>
#include<assert.h>

void InitQueueS(QueueS queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
}
static bool IsFull(QueueS queue) 
{
	return (queue->rear+1)%SIZE == queue->front;
}
bool Push(QueueS queue,int val)
{
	if(IsFull(queue))
	{
		return false;
	}
	queue->elem[queue->rear] = val;
	queue->rear = (queue->rear+1)%SIZE;
	return true;
}

bool Pop(QueueS queue,int *rtv)
{
	if(IsEmpty(queue))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = queue->elem[queue->front];
	}
	queue->front = (queue->front+1)%SIZE;
	return true;
}

void Show(QueueS queue)
{
	for(int i = queue->front; i != queue->rear;i = (i+1)%SIZE)
	{
		printf("%d ",queue->elem[i]);
	}
	printf("\n");
}

int GetLength(QueueS queue)
{
	return (queue->rear-queue->front + SIZE)%SIZE;
}

bool IsEmpty(QueueS queue)
{
	return queue->front == queue->rear;
}

void Clear(QueueS queue)
{
	queue->front = queue->rear;
}

void Destroy(QueueS queue);
void EnterStack(Queue *qu1, Queue *qu2, int val)
{
	Push(qu1, val);
}
int PopStack(Queue *qu1, Queue *qu2)
{
	int i = 0;int m = 0;
	while (m == 0)
	{
		int *m = NULL;
		int p = qu1->rear;
		qu1->front = 0;
		for (i = 0;i < p - 1;i++)
		{
			int n = qu1->elem[i];
			Pop(qu1, m);
			Push(qu2, n);
		}
		Pop(qu1, m);
		int n = qu1->elem[qu1->front - 1];
		printf("%d", n);
		int l = qu2->rear;
		qu2->front = 0;
		for (i = 0;i < l - 1;i++)
		{
			int n = qu2->elem[i];
			Pop(qu2, m);
			Push(qu1, n);
		}
		Pop(qu2, m);
		n = qu2->elem[qu2->front - 1];
		printf("%d", n);
	}

	return 0;
}//这是两个队列实现栈，
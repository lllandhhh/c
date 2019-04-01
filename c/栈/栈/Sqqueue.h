#pragma once
#define SIZE 10
typedef struct Queue
{
	int elem[SIZE];
	int front;
	int rear;
}Queue,*QueueS;
void InitQueueS(QueueS queue);

bool Push(QueueS queue,int val);

bool Pop(QueueS queue,int *rtv);

void Show(QueueS queue);

int GetLength(QueueS queue);

bool IsEmpty(QueueS queue);

void Clear(QueueS queue);

void Destroy(QueueS queue);
void EnterStack(Queue *qu1, Queue *qu2, int val);

int PopStack(Queue *qu1, Queue *qu2);

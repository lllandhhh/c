#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct HNode
{
	struct Node *front;//ͷ
	struct Node *last;//β
}HNode,*QueueList;

void InitQueueL(QueueList queue);

bool Push(QueueList queue,int val);

bool Pop(QueueList queue,int *rtv);

void Show(QueueList queue);

int GetLength(QueueList queue);

bool IsEmpty(QueueList queue);

void Clear(QueueList queue);

void Destroy(QueueList queue);
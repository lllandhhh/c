#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node,*Pstack;
void InitStack(Pstack ps);

bool Push(Pstack ps,int val);

bool Pop(Pstack ps,int *rtv);//ɾ��

bool GetTop(Pstack ps,int *rtv);

bool IsEmpty(Pstack ps);

void Destroy(Pstack ps);

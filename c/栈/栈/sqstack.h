#pragma once
#define STACK_LEN  10
typedef struct Sqstack 
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;
void InitStack(Pstack ps);

bool Push(Pstack ps,int val);

bool Pop(Pstack ps,int *rtv);//ɾ��

bool GetTop(Pstack ps,int *rtv);//�õ�ջ��Ԫ�أ� ���ǲ�ɾ��

bool IsEmpty(Pstack ps);

void Clear(Pstack ps);//top ָ��Ĳ���

void Destroy(Pstack ps);//����û�ж�̬�ڴ����

void Show(Pstack ps);
int PopQueue(Pstack s1, Pstack s2);
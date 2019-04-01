#include"sqstack.h"
#include<stdio.h>
#include<assert.h>
void InitStack(Pstack ps)
{
	assert(ps != NULL);
	ps->top = 0;
}
static bool isFull(Pstack ps)
{
	return ps->top == STACK_LEN;
}
bool Push(Pstack ps,int val)
{
	if(isFull(ps)) 
	{
		return false;
	}
	ps->elem[ps->top++] = val;
	return true;
}
bool IsEmpty(Pstack ps)
{
	return ps->top == 0;
}

bool Pop(Pstack ps,int *rtv)//删除
{
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		ps->top--;
		*rtv = ps->elem[ps->top];
	}
	return true;
}

bool GetTop(Pstack ps,int *rtv)//得到栈顶元素， 但是不删除
{
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = ps->elem[ps->top-1];
	}
	return true;
}


void Clear(Pstack ps)//top 指针的操作
{
	ps->top = 0;
}

void Destroy(Pstack ps)
{
	Clear(ps);
}
void Show(Pstack ps)
{
	for(int i = 0;i < ps->top;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}
void EnterQue(Pstack s1, int val)
{
	Push(s1,val);
}
int PopQueue(Pstack s1, Pstack s2)//这是两个栈实现一个队列框架
{
	int *m = NULL;
	if (IsEmpty(s2))
	{
		int p = s1->top;
		for (int i = 0;i < p;i++)
		{
			Push(s2, s1->elem[i]);
			Pop(s1, m);
		}
	}
	return 0;
}

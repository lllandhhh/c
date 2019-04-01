#include"Lstack.h"
#include<assert.h>
#include<stdlib.h>
void InitStack(Pstack ps)
{
	assert(ps!=NULL);
	ps->next = NULL;
}
static Node *GetNode(int val)
{
	Node *pGet = (Node*)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
bool Push(Pstack ps,int val)
{
	Node *pGet = GetNode(val);
	pGet->next = ps->next;
	ps->next = pGet;
	return true;
}

bool Pop(Pstack ps,int *rtv)//É¾³ý
{
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = ps->next->data;
	}
	Node *pDel = ps->next;
	ps->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return true;
}

bool GetTop(Pstack ps,int *rtv)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = ps->next->data;
	}
	return true;
}

bool IsEmpty(Pstack ps)
{
	return ps->next == NULL;
}

void Destroy(Pstack ps)
{
	Node *p = NULL;
	while(ps->next != NULL)
	{
		p = ps->next;
		ps->next = p->next;
		free(p);
	}
	p = NULL;
}
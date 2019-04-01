#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *List;

void InitList(List plist)
{
	assert(plist != NULL);
	plist->next = NULL;
}
static Node* GetNode(int val)
{
	Node *pGet = (Node*)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
bool Insert(List plist, int val)
{
	Node *p = plist;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node *pGet = GetNode(val);
	p->next = pGet;
	return true;
}
bool DeleteFirst(List plist, int *rtv)
{
	Node *pDel = plist->next;
	if (pDel == NULL)
	{
		return false;
	}
	*rtv = pDel->data;
	plist->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return true;
}
//123 === > 3λ��  n   123/10 12/10 = 1   1/10 = 0 
int GetMaxBit(int *arr, int len)
{
	//1����Ҫ�ҵ���������ֵ
	int max = arr[0];
	for (int i = 1;i < len;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//2��������ֵ��λ��
	int count = 0;
	while (max != 0)//123
	{
		count++;//1  2  3
		max /= 10;//12  1   0
	}
	return count;
}
//123--->  123%10   123/10%10==2   123/10/10%10-->1
int GetNum(int num, int figures)
{
	for (int i = 0;i < figures;i++)
	{
		num /= 10;
	}
	return num % 10;
}
//figures-->������������figuresλ������  0  ==�� ��λ
void Radix(int *arr, int len, int figures)
{
	Node head[10];//
	for (int i = 0;i < 10;i++)
	{
		InitList(&head[i]);
	}
	//1����Ͱ--���õ������жϵ�figuresλΪ���ֶ��٣�
	//����Ӧ��Ͱ��
	int tmp = 0;
	int i = 0;
	for (; i < len;i++)
	{
		tmp = GetNum(arr[i], figures);
		Insert(&head[tmp], arr[i]);
	}
	//2����Ͱ
	i = 0;
	for (int j = 0;j < 10;)//j����Ͱ�ĸ������±�
	{
		if (DeleteFirst(&head[j], &arr[i]))
		{
			i++;
		}
		else
		{
			j++;
		}
	}
}
//O(d*n)
void RadixSort(int *arr, int len)
{
	int count = GetMaxBit(arr, len);
	for (int i = 0;i < count;i++)//d
	{
		Radix(arr, len, i);//n
	}
}

void Show(int *arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 12,88,3333,999,4343,223,212,7676,343 };
	int len = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr, len);
	Show(arr, len);
	getchar();
	return 0;
}
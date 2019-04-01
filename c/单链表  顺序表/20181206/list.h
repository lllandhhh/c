#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;
void InitList(List plist);//��ʼ��������

bool Insert_head(List plist,int val);//ͷ�巨

bool Insert_tail(List plist,int val);//β�巨

bool Insert_pos(List plist,int pos,int val);//pos λ�ò���

Node *Search_pre(List plist,int key);//���� key ��ǰ��

bool Delete(List plist,int key);//ɾ�� key ������

bool IsEmpty(List plist);//�Ƿ�Ϊ��

void Destroy(List plist);//�ݻٺ���������ж�̬�����ڴ棩

int GetLength(List plist);//�õ�������ĳ���

void Show(List plist);//��ӡ������
void nizhi(List plist);

Node *ListK(List plist, int k);//�ҳ�������K���ڵ�
void dlist(List plist, int k);//ɾ�� ������K���ڵ�
bool lscut(List plist1, List plist);//�ж����������� �Ƿ��ཻ
Node* MergeList(List plist1, List plist2);
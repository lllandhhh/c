#pragma once
typedef struct CNode
{
	int data;
	struct CNode *next;
}CNode, *CList;
void InitList(CList plist);//��ʼ��
bool Insert_head(CList plist, int val);//ͷ�巨
bool Insert_tail(CList plist, int val);//β�巨
CNode *Search_pri(CList plist, int key);//����ǰ��
bool Delete(CList plist, int key);//ɾ��
bool IsEmpty(CList plist);//�Ƿ�Ϊ��
void Destroy(CList plist);//�ݻ�
int GetLength(CList plist);//�õ�����
void Show(CList plist);//��ʾ����

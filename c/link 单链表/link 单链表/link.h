#pragma once
typedef struct Node
{
	int data;
	struct Node *next;//放的是 下一表的 地址；
}Node, *List;

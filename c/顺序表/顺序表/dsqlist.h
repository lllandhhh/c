#pragma once
#pragma once//预防头文件重复引用
#define in_SIZE 10
typedef  struct DSplist//动态开辟 顺序表
{
	int *elem;
	int usedsize;
	int size;
}DSqlist, *PDSqlist;
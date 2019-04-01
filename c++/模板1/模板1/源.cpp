#include<stdio.h>
#include<string.h>

template<typename T>
void sort(T a[10])
{
	T k;
	for (int i = 0;i<10-1;i++)
		for (int j = 0;j<10-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				 k = a[j+1], a[j+1] = a[j], a[j] = k;
			}
		}
}
template<>
void  sort<char *>(char *arr[] )
{
	char *k;
	for (int i = 0;i<3 - 1;i++)
		for (int j = 0;j<3 - i - 1;j++)
		{
			if (strcmp(arr[j],arr[j + 1])>0)
			{
				k = arr[j + 1], arr[j + 1] = arr[j], arr[j] = k;
			}
		}
 }
template<typename T>
bool compare(const T &a, const T &b)
{
	return a > b;
}
template<>
bool compare<char *>(char* const&a, char * const&b)
{
	return (strcmp(a, b) > 0);
}
template<typename T>
int findValue(T arr[], int size, const T &val)
{
	int i = 0;
	for(i;i<size;i++)
	{
		if (arr[i] == val)return i;
		if (i = size)return -1;
	}
}
template<>
int findValue<char *>(char * arr[], int size, char *const  &val)
{
	int i = 0;
	for (i;i<size;i++)
	{
		if (strcmp(arr[i] , val)==0)return i;
	}
	if (i = size)return -1;
}
int main()
{
	//int a[10] = { 1,4,5,7,9,6,2,3,7,9 };
	//char *arr[3] = { "bc","cd","af" };
	//sort<int>(a);
	//sort<char *>(arr);
	//char aa[] = "aaa";
	//char bb[] = "bbb";
	//compare<char *>(aa, bb);
	//for (int i = 0;i < 3;i++)
	//{
	//	printf("%s", arr[i]);
	//}
	char *a[3] = { "aa","bb","cc" };
	int i=findValue<char *>(a, 3, "cc");
	printf("%d", i);
	getchar();
	return 0;
}

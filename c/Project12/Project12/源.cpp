#include<stdio.h>
#include<iostream>
using namespace std;
#define n 3
#define q 5
struct work

{
	int max[n];
	int allocation[n];
	int need[n];
};

void workput(work p[q])//输入数据
{
	for (int j = 0;j < q;j++)
	{
		cout << "max";
		int i = 0;int m = 0;
		for ( i = 0;i < n;i++)
		{
			 m = 0;
			cin >> m;
			p[j].max[i] = m;
		}
		cout << "allocation";
		for (i = 0;i < n;i++)
		{
			m = 0;
			cin >> m;
			p[j].allocation[i] = m;
		}
		cout << "need";
		for (i = 0;i < n;i++)
		{
			m = 0;
			cin >> m;
			p[j].need[i] = m;
		}
	}
}
void safe(work p[q],int a[n])//安全算法
{int work[n]= { 3,3,2 };
	int m = q;
	int tpm[q] = { 0,0,0,0,0 };
	int i;
	int j;
	int l=0;
	while (m>0)
	{
		l++;
		if (l > 5)
		{
			cout << "找不到安全序列";break;
		}
		for ( i = 0;i < q;i++)
		{
			int tmp = 3;
			if (tpm[i] == 1)continue;
			for (int j = 0;j < n;j++)
			{
				if (p[i].need[j] <= work[j])tmp--;
				if (p[i].need[j] > p[i].max[i])
				{
					cout << "请求资源超过最大资源" << endl;

				}
			}
			if (tmp == 0)
			{
				for ( j = 0;j < n;j++)
				{
					work[j] = work[j] + p[i].allocation[j];
				}
				m--;tpm[i] = 1;cout << "安全序列为   " << i << endl;
			}
		}
	}
}
void
int main()
{
	int a[n] = {3,3,2};
	work p[q];
	workput(p);
	safe(p, a);
	getchar();
	getchar();
	return 0;
}
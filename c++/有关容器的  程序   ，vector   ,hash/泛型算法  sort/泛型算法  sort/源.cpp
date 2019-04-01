#include <iostream>
#include <vector>  // ʹ��vector����
#include <algorithm>  // ʹ�÷����㷨
using namespace std;

template<typename T>
bool comp_greater(T a, T b)
{
	return a > b;
}
template<typename T>
bool comp_less(T a, T b)
{
	return a < b;
}


// ����ָ������ĺ�������
template<typename T>
class MyGreater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};
template<typename T>
class MyLess
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

template<typename Iterator, typename Compare>
void mysort(Iterator first, Iterator last, Compare comp)
{
	// ������������sort�������Զ�������
	typename Iterator::value_type tmp;
	int size = last - first;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (comp(*(first + j), *(first + j + 1)))
			{
				tmp = *(first + j);
				*(first + j) = *(first + j + 1);
				*(first + j + 1) = tmp;
			}
		}
	}
}

template<typename Container>
void showContainer(const Container &con)
{
	// const int *p   int *const p;
	typename Container::const_iterator it = con.begin();
	for (; it != con.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
// �Լ�ʵ��sort�����㷨
template<typename Iterator>
void mysort(Iterator first, Iterator last)
{
	// ������������sort��Ĭ����С������������
	typename Iterator::value_type tmp;
	int k = last - first;
	for(int i=0;i<k-1;i++)
		for (int j = 0;j < k - 1-i;j++)
		{
			if (*(first + j) > *(first + j + 1))
			{
				tmp = *(first + j);
				*(first + j) = *(first + j + 1);
				*(first + j + 1) = tmp;
			}
		}
}
int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	showContainer(vec);

	// ��vectorĬ������
	mysort(vec.begin(), vec.end());
	showContainer(vec);
	/*mysort(vec.begin(), vec.end(), comp_greater<int>);
	showContainer(vec);*/

	mysort(vec.begin(), vec.end(), MyLess<int>());
	showContainer(vec);
	getchar();
	return 0;
}

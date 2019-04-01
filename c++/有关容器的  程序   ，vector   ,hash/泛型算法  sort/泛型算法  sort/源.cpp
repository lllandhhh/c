#include <iostream>
#include <vector>  // 使用vector容器
#include <algorithm>  // 使用泛型算法
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


// 定义指定排序的函数对象
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
	// 带三个参数的sort，可以自定义排序
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
// 自己实现sort泛型算法
template<typename Iterator>
void mysort(Iterator first, Iterator last)
{
	// 带两个参数的sort，默认是小到大进行排序的
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

	// 给vector默认排序
	mysort(vec.begin(), vec.end());
	showContainer(vec);
	/*mysort(vec.begin(), vec.end(), comp_greater<int>);
	showContainer(vec);*/

	mysort(vec.begin(), vec.end(), MyLess<int>());
	showContainer(vec);
	getchar();
	return 0;
}

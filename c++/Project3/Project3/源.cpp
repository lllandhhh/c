#include <iostream>
#include <vector>  // 使用vector容器
#include <algorithm>  // 使用泛型算法
#include <functional> // C++ STL的函数对象 greater less greater_equal less_
#include <typeinfo>
#include <string>
#include<queue>
#include <list>
using namespace std;

template<typename T>
class CHash
{
public:
	int operator()(const T &val)
	{
		// 默认用除留余数法
		return val;
	}
}; // string  User  People

template<>
class CHash<string>
{
public:
	int operator()(const string &val)
	{
		// hello  olleh
		int sum = 0;
		for (int i = 0; i < val.length(); ++i)
		{
			sum += (val[i] >> i);
		}
		return sum;
	}
};
// 链地址法实现的哈希表结构 
template<typename T, typename HashType = CHash<T>>
class CHashTable
{
public:
	CHashTable(int size = 3, double lf = 0.75)
		:_loadFactor(lf), _usedBuckets(0)
	{
		// 给哈希表开辟数组空间的
		_hashVec.resize(size);
	}
	void put(const T &val)
	{
		double lf = _usedBuckets * 1.0 / _hashVec.size();
		cout << "size:" << _hashVec.size() << " loadfactor:" << lf << endl;
		if (lf >= _loadFactor)
		{
			resize();
		}
		int index = _hash(val) % _hashVec.size();
		list<int> &curList = _hashVec[index];
		if (curList.empty())
		{
			curList.push_front(val);
			_usedBuckets++;
		}
		else
		{
			auto it = find(curList.begin(), curList.end(), val);
			if (it == curList.end())
			{
				curList.push_front(val);
			}
		}
	}
	// 删除哈希表中的元素
	void remove(const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		list<int> &curList = _hashVec[index];
		if (!curList.empty())
		{
			// 1.在list怎么找val
			auto it = find(curList.begin(), curList.end(), val);
			// 2.找到val，删除，找不到，return
			if (it != curList.end())
			{
				curList.erase(it);
				// 3.删除val，如果桶变成空的，要给
				if (curList.empty())
				{
					_usedBuckets--;
				}
			}
		}
	}
	// 在哈希表中查找元素   table.query(10);    table[10]
	bool operator[](const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		list<int> &curList = _hashVec[index];
		if (!curList.empty())
		{
			// 1.在list怎么找val
			auto it = find(curList.begin(), curList.end(), val);
			// 2.找到val，删除，找不到，return
			if (it != curList.end())
			{
				return true;
			}
		}
		return false;
	}

private:
	vector<list<int>> _hashVec;
	double _loadFactor; // 记录加载因子
	int _usedBuckets;
	HashType _hash;  // 专门计算T类型对象的哈希值的

					 //获取素数
	int getPrime(int n)
	{
		for (int i = n + 1;; ++i)
		{
			int k = sqrt(i);
			int j = 2;
			for (; j <= k; ++j)
			{
				if (i % j == 0)
					break;
			}
			if (j > k)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
	}

	// 动态扩容
	void resize()
	{
		// 1.先把现有的哈希表交换到老的容器当中
		vector<list<int>> _oldhash;
		_oldhash.swap(_hashVec);

		// 2.给_hashVec resize桶内存
		_hashVec.resize(getPrime(_oldhash.size()));

		// 3.遍历old哈希表，的每一个链表的节点，计算其散列码，splice到新的hash中
		for (auto it = _oldhash.begin(); // it -> list<int>
			it != _oldhash.end();
			++it)
		{
			if (!it->empty())
			{
				for (auto it1 = it->begin(); it1 != it->end();)
				{
					int index = _hash(*it1) % _hashVec.size();
					list<int> &mylist = _hashVec[index];
					if (!mylist.empty())
					{
						// 4.如果桶被第一次占用，_usedBuckets++
						_usedBuckets++;
					}
					// 把旧的hash表中的list节点直接搬到新的哈希表当中
					mylist.splice(mylist.begin(), *it, it1);
					it1 = it->begin();
				}

				/*
				for (auto it1 = it->begin();  // it1 -> int
				it1 != it->end();
				++it1)
				{
				int index = _hash(*it1) % _hashVec.size();
				list<int> &mylist = _hashVec[index];
				if (!mylist.empty())
				{
				// 4.如果桶被第一次占用，_usedBuckets++
				_usedBuckets++;
				}
				// 把旧的hash表中的list节点直接搬到新的哈希表当中
				mylist.splice(mylist.begin(), *it, it1);
				}
				*/
			}
		}
	}
};
int main()
{
	CHashTable<int> hash;
	for (int i = 0; i < 8; i++)
	{
		hash.put(i);
	}

	return 0;
}
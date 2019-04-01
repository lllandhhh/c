#include <iostream>
#include <vector>  // 使用vector容器
#include <algorithm>  // 使用泛型算法
#include <functional> // C++ STL的函数对象 greater less greater_equal less_
#include <typeinfo>
#include <string>
#include<list>
using namespace std;

// 计算哈希值的类
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

// 线性探测法实现的哈希表结构 
template<typename T, typename HashType = CHash<T>>
class CHashTable
{
public:
	CHashTable(int size = 3, double lf = 0.75)
		:_loadFactor(lf)
	{
		// 给哈希表开辟数组空间的
		_hashVec.resize(size);
		// 给计算哈希值的对象设置桶的大小
		//_hash.setBucketNumber(size);
	}
	void put(const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		for (int i = index;; i = (i + 1) % _hashVec.size())
		{
			// STATE_UNUSE STATE_USE STATE_USED
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
			}
		}
	}
	void  operator[]()
	{
	
	}
private:
	// STATE_UNUSE   删除 STATE_USED 0
	enum STATE { STATE_UNUSE, STATE_USE, STATE_USED };
	vector< list <T>> _hashVec;
	double _loadFactor; // 记录加载因子
	HashType _hash;  // 专门计算T类型对象的哈希值的
};

int main()
{
	vector< list <int>> a;

	return 0;
}
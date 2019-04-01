#include <iostream>
#include <vector>  // ʹ��vector����
#include <algorithm>  // ʹ�÷����㷨
#include <functional> // C++ STL�ĺ������� greater less greater_equal less_
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
		// Ĭ���ó���������
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
// ����ַ��ʵ�ֵĹ�ϣ��ṹ 
template<typename T, typename HashType = CHash<T>>
class CHashTable
{
public:
	CHashTable(int size = 3, double lf = 0.75)
		:_loadFactor(lf), _usedBuckets(0)
	{
		// ����ϣ��������ռ��
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
	// ɾ����ϣ���е�Ԫ��
	void remove(const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		list<int> &curList = _hashVec[index];
		if (!curList.empty())
		{
			// 1.��list��ô��val
			auto it = find(curList.begin(), curList.end(), val);
			// 2.�ҵ�val��ɾ�����Ҳ�����return
			if (it != curList.end())
			{
				curList.erase(it);
				// 3.ɾ��val�����Ͱ��ɿյģ�Ҫ��
				if (curList.empty())
				{
					_usedBuckets--;
				}
			}
		}
	}
	// �ڹ�ϣ���в���Ԫ��   table.query(10);    table[10]
	bool operator[](const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		list<int> &curList = _hashVec[index];
		if (!curList.empty())
		{
			// 1.��list��ô��val
			auto it = find(curList.begin(), curList.end(), val);
			// 2.�ҵ�val��ɾ�����Ҳ�����return
			if (it != curList.end())
			{
				return true;
			}
		}
		return false;
	}

private:
	vector<list<int>> _hashVec;
	double _loadFactor; // ��¼��������
	int _usedBuckets;
	HashType _hash;  // ר�ż���T���Ͷ���Ĺ�ϣֵ��

					 //��ȡ����
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

	// ��̬����
	void resize()
	{
		// 1.�Ȱ����еĹ�ϣ�������ϵ���������
		vector<list<int>> _oldhash;
		_oldhash.swap(_hashVec);

		// 2.��_hashVec resizeͰ�ڴ�
		_hashVec.resize(getPrime(_oldhash.size()));

		// 3.����old��ϣ����ÿһ������Ľڵ㣬������ɢ���룬splice���µ�hash��
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
						// 4.���Ͱ����һ��ռ�ã�_usedBuckets++
						_usedBuckets++;
					}
					// �Ѿɵ�hash���е�list�ڵ�ֱ�Ӱᵽ�µĹ�ϣ����
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
				// 4.���Ͱ����һ��ռ�ã�_usedBuckets++
				_usedBuckets++;
				}
				// �Ѿɵ�hash���е�list�ڵ�ֱ�Ӱᵽ�µĹ�ϣ����
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
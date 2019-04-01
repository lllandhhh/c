#include <iostream>
#include <vector>  // ʹ��vector����
#include <algorithm>  // ʹ�÷����㷨
#include <functional> // C++ STL�ĺ������� greater less greater_equal less_
#include <typeinfo>
#include <string>
#include<list>
using namespace std;

// �����ϣֵ����
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

// ����̽�ⷨʵ�ֵĹ�ϣ��ṹ 
template<typename T, typename HashType = CHash<T>>
class CHashTable
{
public:
	CHashTable(int size = 3, double lf = 0.75)
		:_loadFactor(lf)
	{
		// ����ϣ��������ռ��
		_hashVec.resize(size);
		// �������ϣֵ�Ķ�������Ͱ�Ĵ�С
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
			}
		}
	}
	void  operator[]()
	{
	
	}
private:
	// STATE_UNUSE   ɾ�� STATE_USED 0
	enum STATE { STATE_UNUSE, STATE_USE, STATE_USED };
	vector< list <T>> _hashVec;
	double _loadFactor; // ��¼��������
	HashType _hash;  // ר�ż���T���Ͷ���Ĺ�ϣֵ��
};

int main()
{
	vector< list <int>> a;

	return 0;
}
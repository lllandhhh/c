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
	//CHashTable(int size = 7, double lf = 0.75)
	CHashTable(int size = 3, double lf = 0.0, int len = 0)
		:_loadFactor(lf), _len(len)
	{
		// 给哈希表开辟数组空间的
		_hashVec.resize(size);
		// 给计算哈希值的对象设置桶的大小
		//_hash.setBucketNumber(size);
	}
	void put(const T &val)
	{
		if (_len / _hashVec.size() >= _loadFactor)
		{
			_len = 0;
			ice_size();
		}
		int index = _hash(val) % _hashVec.size();
		for (int i = index;; i = (i + 1) % _hashVec.size())
		{
			if (_hashVec[i]._state == STATE_UNUSE || _hashVec[i]._state == STATE_USED)
			{
				_hashVec[i]._data = val;
				_hashVec[i]._state = STATE_USE;
				_len++;
				_loadFactor = (double)_len / _hashVec.size();
				break;
			}
		}
	}
	// 删除哈希表中的元素
	void remove(const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		for (int i = index;;i = (i + 1) % _hashVec.size())
		{
			if (_hashVec[i]._data == val)
			{
				_hashVec[i]._data = 0;
				_hashVec[i]._state = STATE_USED;
				_len--;
				_loadFactor = (double)_len / _hashVec.size();
				break;
			}

		}
	}
	// 在哈希表中查找元素
	bool query(const T &val)
	{
		int index = _hash(val) % _hashVec.size();
		int flag = index - 1;
		for (int i = index;;i = (i + 1) % _hashVec.size())
		{
			if (_hashVec[i]._data == val)
			{
				return true;
			}
			else if (i == flag)
			{
				return false;
			}
			else
			{
				continue;
			}
		}
	}

	void display()
	{
		for (int i = 0;i < _hashVec.size();++i)
		{
			cout << _hashVec[i]._data << " ";
		}
		cout << endl;
	}
private:
	// STATE_UNUSE   删除 STATE_USED 0
	enum STATE { STATE_UNUSE, STATE_USE, STATE_USED };
	struct Node
	{
		Node(T data = T())
			:_data(data), _state(STATE_UNUSE)
		{}
		T _data;
		STATE _state;
	};
	vector<Node> _hashVec;
	int _len;           //表示存入元素的个数 
	double _loadFactor; // 记录加载因子
	int _prime;
	HashType _hash;     // 专门计算T类型对象的哈希值的
	int get_prime(int n)//获取素数
	{
		for (int i = n + 1;;++i)
		{
			int k = sqrt(i);
			int j = 2;
			for (;j <= k;++j)
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
	void ice_size()         // 动态扩容
	{
		vector<Node> _newhash;
		_newhash.resize(get_prime(_hashVec.size()));
		for (int i = 0;i < _hashVec.size(); ++i)
		{
			// STATE_UNUSE STATE_USE STATE_USED
			if (_hashVec[i]._state == STATE_USE)
			{
				int index = _hashVec[i]._data % _newhash.size();
				for (int j = index; ; j = (j + 1) % _newhash.size())
				{
					if (_newhash[j]._state == STATE_UNUSE || _newhash[j]._state == STATE_USED)
					{
						_newhash[j]._data = _hashVec[i]._data;
						_newhash[j]._state = STATE_USE;
						_len++;
						_loadFactor = (double)_len / _newhash.size();
						break;
					}
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		_hashVec.erase(_hashVec.begin(), _hashVec.end());
		_hashVec = _newhash;
	}
};

int main()
{
	CHashTable<int> hash;
	srand(time(NULL));
	for (int i = 0;i < 8;i++)
	{
		//hash.put(rand() % 100 + 1);
		hash.put(i);
	}
	hash.put(2);
	hash.display();
	hash.remove(2);
	hash.display();
	hash.put(2);
	hash.display();
	cout << hash.query(3) << endl;
	cout << hash.query(2) << endl;
	return 0;
}

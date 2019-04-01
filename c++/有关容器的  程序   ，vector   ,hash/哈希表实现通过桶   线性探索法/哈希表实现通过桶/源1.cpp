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
	//CHashTable(int size = 7, double lf = 0.75)
	CHashTable(int size = 3, double lf = 0.0, int len = 0)
		:_loadFactor(lf), _len(len)
	{
		// ����ϣ��������ռ��
		_hashVec.resize(size);
		// �������ϣֵ�Ķ�������Ͱ�Ĵ�С
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
	// ɾ����ϣ���е�Ԫ��
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
	// �ڹ�ϣ���в���Ԫ��
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
	// STATE_UNUSE   ɾ�� STATE_USED 0
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
	int _len;           //��ʾ����Ԫ�صĸ��� 
	double _loadFactor; // ��¼��������
	int _prime;
	HashType _hash;     // ר�ż���T���Ͷ���Ĺ�ϣֵ��
	int get_prime(int n)//��ȡ����
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
	void ice_size()         // ��̬����
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

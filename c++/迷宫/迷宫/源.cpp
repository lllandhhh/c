// 20190226.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <iostream>
using namespace std;
/*
1.�������������
2.const��*  const��** const��&
const int* => int*   err
int * => const int*  ok
int ** => const int**  err
const int** => int**  err

int** => int *const*  err
int*const* => int**   err
const int** => int *const*  err
*/

/*
��OOP����Թ�·����Ѱ�����⣬�������Ҫ�����£�
�������Թ����������� 5 5
�������Թ�·���ڵ���Ϣ��1��ʾ�����ߣ�0��ʾ���ߣ�
0 0 1 0 1
0 0 1 0 0
1 0 0 1 0
0 1 0 0 0
��ʼѰ���Թ�·���������Ͻǵ����½ǵ�һ����ͨ�е�·����:
�Թ������ڿ�ͨ�е�·��
* * 1 0 1
0 * 1 0 0
1 * * 1 0
0 1 * * *
*/
const int WAY_CNT = 4;   // �ܵķ�����Ŀ
const int WAY_RIGHT = 0;//��
const int WAY_DOWN = 1;//��
const int WAY_LEFT = 2;//��
const int WAY_UP = 3;  //��

const int WAY_STATE_OK = 5; // ·�������������
const int WAY_STATE_ERR = 6;  // ·������������

class MazeNode  // �Թ��ڵ�����
{
public:
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setVal(int val) { _val = val; }
	int getVal() { return _val; }
	void setWayState(int way, int state) { _state[way] = state; }
	int  getX() {	return _x;}
	int getY() { return _y; }
	int getstate(int a)
	{
		return _state[a];
	}
private:
	int _val;
	int _x;
	int _y;
	int _state[WAY_CNT];
};
class CSeqtack  // ջ����
{
public:
	CSeqtack(int size = 10)
		:_top(0), _size(size)
	{
		_stack = new MazeNode[_size];
	}
	void push(const MazeNode &node)
	{
		if (_top == _size)
		{
			MazeNode *ptmp = new MazeNode[2 * _size];
			for (int i = 0; i < _size; ++i)
			{
				ptmp[i] = _stack[i];
			}
			delete[]_stack;
			_stack = ptmp;
			_size *= 2;
		}
		_stack[_top++] = node;
	}
	void pop()
	{
		if (_top == 0)
			return;
		--_top;
	}
	MazeNode top()
	{
		return _stack[_top - 1];
	}
	bool empty() { return _top == 0; }
	bool full() { return _top == _size; }
private:
	MazeNode *_stack;
	int _top;
	int _size;

	CSeqtack(const CSeqtack&);
	CSeqtack& operator=(const CSeqtack&);
};
class Maze  // �Թ�����
{
public:
	Maze(int r = 10, int c = 10)
		:_row(r), _col(c)
	{
		_pMazes = new MazeNode*[_row];
		for (int i = 0; i < _row; ++i)
		{
			_pMazes[i] = new MazeNode[_col];
		}
	}
	void initMazeNode(int x, int y, int val)
	{
		_pMazes[x][y].setX(x);
		_pMazes[x][y].setY(y);
		_pMazes[x][y].setVal(val);
		for (int i = 0; i < WAY_CNT; ++i)
		{
			_pMazes[x][y].setWayState(i, WAY_STATE_OK);
		}
	}
	void adjustMazeNode()
	{
		for (int i = 0; i < _row; ++i)
		{
			for (int j = 0; j < _col; ++j)
			{
				if (_pMazes[i][j].getVal() == 1)
					continue;

				if (i == 0)
				{
					_pMazes[i][j].setWayState(WAY_UP, WAY_STATE_ERR);
				}
				if (j == 0)
				{
					_pMazes[i][j].setWayState(WAY_LEFT, WAY_STATE_ERR);
				}
				if (j == _col - 1)
				{
					_pMazes[i][j].setWayState(WAY_RIGHT, WAY_STATE_ERR);
				}
				if (i == _row - 1)
				{
					_pMazes[i][j].setWayState(WAY_DOWN, WAY_STATE_ERR);
				}
				if (j < _col - 1 && _pMazes[i][j + 1].getVal() == 1)
				{
					_pMazes[i][j].setWayState(WAY_RIGHT, WAY_STATE_ERR);
				}
				if (i < _row - 1 && _pMazes[i + 1][j].getVal() == 1)
				{
					_pMazes[i][j].setWayState(WAY_DOWN, WAY_STATE_ERR);
				}
				if (j > 0 && _pMazes[i][j - 1].getVal() == 1)
				{
					_pMazes[i][j].setWayState(WAY_LEFT, WAY_STATE_ERR);
				}
				if (i > 0 && _pMazes[i - 1][j].getVal() == 1)
				{
					_pMazes[i][j].setWayState(WAY_UP, WAY_STATE_ERR);
				}
			}
		}
	}
	void findMazePath()
	{
		if (_pMazes[0][0].getVal() == 1)
		{
			return;
		}

		_stack.push(_pMazes[0][0]);
		while (!_stack.empty())
		{
			MazeNode node = _stack.top();
			int x = node.getX();
			int y = node.getY();
			if (x == _row - 1 && y == _col - 1)
			{
				return;
			}

			//const int WAY_RIGHT = 0;//��
			//const int WAY_DOWN = 1;//��
			//const int WAY_LEFT = 2;//��
			//const int WAY_UP = 3;  //��

			//const int WAY_STATE_OK = 5; // ·�������������
			//const int WAY_STATE_ERR = 6;  // ·������������

			// ���ұ��Ƿ������
			
				if (node.getstate(WAY_RIGHT) == 5)
				{
					y++;
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// ���±��Ƿ������
				if (node.getstate(WAY_DOWN) == 5)
				{
					x++;
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// ������Ƿ������
				if (node.getstate(WAY_LEFT) == 5)
				{
					_stack.pop();
					y--;
					_pMazes[x][y].setWayState(0, 6);
					_stack.pop();
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// ���ϱ��Ƿ������
				if (node.getstate(WAY_LEFT) == 5)
				{
					_stack.pop();
					x--;
					_pMazes[x][y].setWayState(1, 6);
					_stack.pop();
					_stack.push(_pMazes[x][y]);
					continue;
				}
				//_stack.pop();
			}
		
	}
	void showMazePath()
	{
		if (_stack.empty())
		{
			cout << "�Թ������ڿ�ͨ�е�·��" << endl;
			return;
		}

		while (!_stack.empty())
		{
			MazeNode top = _stack.top();
			_pMazes[top.getX()][top.getY()].setVal('*');
			_stack.pop();
		}

		for (int i = 0; i < _row; ++i)
		{
			for (int j = 0; j < _col; ++j)
			{
				if (_pMazes[i][j].getVal() == '*')
				{
					cout << "*" << " ";
				}
				else
				{
					cout << _pMazes[i][j].getVal() << " ";
				}
			}
			cout << endl;
		}
	}
private:
	int _row;
	int _col;
	MazeNode **_pMazes;
	CSeqtack _stack;
};
int main()
{
	cout << "�������Թ���������:";
	int row, col;
	cin >> row >> col;

	Maze maze(row, col);

	cout << "�������Թ�·���ڵ���Ϣ��1��ʾ�����ߣ�0��ʾ���ߣ�:" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int data;
			cin >> data;
			// data i, j
			maze.initMazeNode(i, j, data);
		}
	}

	// �����Թ��ڵ㷽�������״̬
	maze.adjustMazeNode();
	// ��ʼѰ���Թ�·��
	maze.findMazePath();
	// ��ӡ�Թ�Ѱ�ҵĽ��
	maze.showMazePath();
	getchar();
	getchar();
	return 0;
}



#if 0
class Test
{
public:// Test() Test(a)  Test(a, b)
	Test(int a = 5, int b = 5) :ma(a), mb(b)
	{
		cout << "Test(int)" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
	Test(const Test &src) :ma(src.ma), mb(src.mb)
	{
		cout << "Test(const Test&)" << endl;
	}
	/*
	1.
	2.
	*/
	Test& operator=(const Test &src)
	{
		cout << "operator=" << endl;
		ma = src.ma;
		mb = src.mb;
		return *this;
	}
private:
	int ma;
	int mb;
};
int main(int argc, char* argv[])
{
	Test t2;
	t2 = (Test)60; // ��ʾ������ʱ���� Test(60)
	t2 = 60; //��ʿ������ʱ����   const Test(60)

	return 0;
}
#endif
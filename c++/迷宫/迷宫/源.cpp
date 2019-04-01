// 20190226.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
using namespace std;
/*
1.对象的生命周期
2.const和*  const和** const和&
const int* => int*   err
int * => const int*  ok
int ** => const int**  err
const int** => int**  err

int** => int *const*  err
int*const* => int**   err
const int** => int *const*  err
*/

/*
用OOP完成迷宫路径的寻找问题，软件运行要求如下：
请输入迷宫的行列数： 5 5
请输入迷宫路径节点信息（1表示不能走，0表示能走）
0 0 1 0 1
0 0 1 0 0
1 0 0 1 0
0 1 0 0 0
开始寻找迷宫路径（从左上角到右下角的一个可通行的路径）:
迷宫不存在可通行的路径
* * 1 0 1
0 * 1 0 0
1 * * 1 0
0 1 * * *
*/
const int WAY_CNT = 4;   // 总的方向数目
const int WAY_RIGHT = 0;//右
const int WAY_DOWN = 1;//下
const int WAY_LEFT = 2;//左
const int WAY_UP = 3;  //上

const int WAY_STATE_OK = 5; // 路径方向可以行走
const int WAY_STATE_ERR = 6;  // 路径方向不能行走

class MazeNode  // 迷宫节点类型
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
class CSeqtack  // 栈类型
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
class Maze  // 迷宫类型
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

			//const int WAY_RIGHT = 0;//右
			//const int WAY_DOWN = 1;//下
			//const int WAY_LEFT = 2;//左
			//const int WAY_UP = 3;  //上

			//const int WAY_STATE_OK = 5; // 路径方向可以行走
			//const int WAY_STATE_ERR = 6;  // 路径方向不能行走

			// 看右边是否可行走
			
				if (node.getstate(WAY_RIGHT) == 5)
				{
					y++;
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// 看下边是否可行走
				if (node.getstate(WAY_DOWN) == 5)
				{
					x++;
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// 看左边是否可行走
				if (node.getstate(WAY_LEFT) == 5)
				{
					_stack.pop();
					y--;
					_pMazes[x][y].setWayState(0, 6);
					_stack.pop();
					_stack.push(_pMazes[x][y]);
					continue;
				}
				// 看上边是否可行走
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
			cout << "迷宫不存在可通行的路径" << endl;
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
	cout << "请输入迷宫的行列数:";
	int row, col;
	cin >> row >> col;

	Maze maze(row, col);

	cout << "请输入迷宫路径节点信息（1表示不能走，0表示能走）:" << endl;
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

	// 调整迷宫节点方向的行走状态
	maze.adjustMazeNode();
	// 开始寻找迷宫路径
	maze.findMazePath();
	// 打印迷宫寻找的结果
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
	t2 = (Test)60; // 显示生成临时对象 Test(60)
	t2 = 60; //隐士生成临时对象   const Test(60)

	return 0;
}
#endif
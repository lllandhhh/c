
/*
OOP实现一个简单的图书馆书籍管理
角色：
学生   ：  查询书籍   查看自己已经借阅的书籍
管理员 ：  查询书籍   借书   还书    借阅历史

实体：  人    书    借阅信息
*/
#include<iostream>
#include<stdio.h>
using namespace std;

//===================人员信息定义=======================
//权限信息定义
const int AUTH_STUDENT = 0; // 学生权限
const int AUTH_MANAGER = 1; // 管理员权限
const int AUTH_INVLAID = 2; // 无效权限
const int NAME_LEN = 20;
const int SEX_LEN = 5;
const int PWD_LEN = 20;

// 用户类
class CUser
{
public:
	CUser()
	{

	}
	CUser(int a, char *b, int c, char *d, char *f, int h)
	{
		mID = a;
		for (int i = 0;i < NAME_LEN;i++)
		{
			mName[i] = b[i];
		}
		age = c;
		for (int i = 0;i < SEX_LEN;i++)
		{
			sex[i] = d[i];
		}
		for (int i = 0;i < PWD_LEN;i++)
		{
			mPassword[i] = f[i];
		}
		mAuth = h;
	}
	~CUser()
	{
	}	int  *getName()
	{
		return mName;
	}
	char *getpwd()
	{
		return  mPassword;
	}
private:
	int mID;
	int mName[NAME_LEN];
	int age;
	char sex[SEX_LEN];
	int mAuth;//权限
	char mPassword[PWD_LEN];
};
// 用户数据库类
class CUserDB
{
public:
	CUserDB(int size = 10)
	{
		pUserArr = new CUser[size];
		mSize = size;
		mIndex = 0;//用户数量多少
	}
	~CUserDB()
	{
		delete[]pUserArr;
		pUserArr = NULL;
	}
	// 添加用户信息
	void addUser(const CUser &user)
	{
		
		pUserArr[mIndex++] = user;
		if (mIndex = mSize)
		{
			CUser *cur = new CUser[mSize*2];
			mSize = mSize * 2;
			for(int i = 0;i < mIndex;i++)
			{
				cur[i] = pUserArr[i];
			}
			delete[]pUserArr;
			pUserArr = cur;
		}
	}
	int checkUser(char *name, char *pwd)// 检查用户登录权限
	{
		return AUTH_STUDENT;
	}

private:
	CUser *pUserArr;
	int mSize;
	int mIndex;
};
//===================书籍信息定义=======================
const int BOOK_NAME_LEN = 50;
const int BOOK_NUM = 100;
// 书籍类型定义
class CBook
{
public:
	int getISBN() { return mISBN; }
private:
	int mISBN;//书号
	char mName[BOOK_NAME_LEN];
	int mAmount;//数量
};

// 书籍的DB定义
class CBookDB
{
public:
	// 添加书籍
	void addBook(const CBook &book)
	{
		mBookArr[mIndex++] = book;
	}
	// 删除书籍
	void delBook(int isbn)
	{
		for (int i = 0; i < mIndex; ++i)
		{
			if (isbn == mBookArr[i].getISBN())
			{
				CBook cur[BOOK_NUM];
				for (int j = 0;j < mIndex;j++)
				{
					if (i = j)continue;
					cur[j]=mBookArr[j];// 数组第i项删除
				}
			}
		}
	}
	// 更新书籍册数
	void updateBookNumber(int isbn, int amount);
	CBook* queryBook(char *name) { return NULL; }
private:
	//CLink mBookLink; // int  CBook
	CBook mBookArr[BOOK_NUM];
	int mIndex;
};
//====================借阅信息定义=====================
class CDate
{
public:
	CDate(int y = 0, int m = 0, int d = 0)
	{
		mYear = y;
		mMonth = m;
		mDay = d;
	}
	void show()
	{
		cout << mYear << "/" << mMonth << "/" << mDay << endl;
	}
private:
	int mYear;
	int mMonth;
	int mDay;
};
const int LOAN_INFO_SIZE = 100;
class CLoan
{
public:

private:
	CUser mUser;
	CBook mBook;
	CDate mborrowTime;
	CDate mbackTime;
	CUser mManager;
};
class CLoanDB
{
public:
	// 添加一条借阅信息
	void addLoan() {}
	void queryStudentLoanInfo(char *username) {}
private:
	CLoan mLoan[LOAN_INFO_SIZE];
	int mIndex;
};
//===================界面类======================
class CMenu
{
public:
	CMenu()
	{
		// 预填写数据
	mUserDB.addUser(CUser(1000, "zhang san", 20, "男", "111", AUTH_STUDENT));
	}
	void loginMenu()
	{
		int choice;
		for (;;)
		{
			cout << "用户名:";
			gets_s(mLoginUser);  // scanf   zhang san
			cout << "密码:";
			char pwd[20];
			gets_s(pwd);
			// 检测用户登录是否成功
			int auth = mUserDB.checkUser(mLoginUser, pwd);
			{
				for (int i = 0;i < mIndex;i++)
					if (pUserArr[i].getName() = mLoginUser)
						cout << "chenggong";
			}
			if (auth != AUTH_INVLAID)
			{
				// 进入相应的主菜单
				if (auth == AUTH_STUDENT) // 进入学生主菜单
				{
					studentMenu();
				}
				else // 进入管理员主菜单
				{
					// managerMenu();
					/*
					1. 查询书籍
					2. 借书    学生名  书籍名 借阅时间  还书时间 CLoan => CLoanDB CBookDB
					3. 还书
					4. 查询借阅历史 CLoanDB => CLoan
					*/
				}
			}
			else
			{
				cout << "用户名或密码错误!重新输入..." << endl;
			}
		}
	}
	//学生操作主菜单
	void studentMenu()
	{
		cout << "============" << endl;
		cout << "1.查询书籍" << endl;
		cout << "2.已借阅书籍" << endl;
		cout << "============" << endl;
		cout << "选择:";
		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "请输入书籍的名称:";
			char name[20];
			gets_s(name);
			CBook *book = mBookDB.queryBook(name);

			if (book == NULL)
			{
				cout << name << " 该书籍不存在！" << endl;
			}
			else
			{
				// 查到以后，打印书籍的信息
			}
		}

		break;
		case 2:
			// 查询借阅信息，有很多，一次进行打印
			mLoanDB.queryStudentLoanInfo(mLoginUser);
			break;
		default:
			cout << "输入无效，请重新选择..." << endl;
		}
	}
private:
	CUserDB mUserDB; // 人员信息数据库
	CBookDB mBookDB; // 书籍信息数据库
	CLoanDB mLoanDB; // 借阅信息数据库
	char mLoginUser[NAME_LEN]; // 记录当前登录的用户名
}; //464-244=220  300
   /*
   界面层  CMenu
   数据层  CBookDB
   */
int main()
{
	CMenu menu;
	menu.loginMenu();
	return 0;
}


/*
OOPʵ��һ���򵥵�ͼ����鼮����
��ɫ��
ѧ��   ��  ��ѯ�鼮   �鿴�Լ��Ѿ����ĵ��鼮
����Ա ��  ��ѯ�鼮   ����   ����    ������ʷ

ʵ�壺  ��    ��    ������Ϣ
*/
#include<iostream>
#include<stdio.h>
using namespace std;

//===================��Ա��Ϣ����=======================
//Ȩ����Ϣ����
const int AUTH_STUDENT = 0; // ѧ��Ȩ��
const int AUTH_MANAGER = 1; // ����ԱȨ��
const int AUTH_INVLAID = 2; // ��ЧȨ��
const int NAME_LEN = 20;
const int SEX_LEN = 5;
const int PWD_LEN = 20;

// �û���
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
	int mAuth;//Ȩ��
	char mPassword[PWD_LEN];
};
// �û����ݿ���
class CUserDB
{
public:
	CUserDB(int size = 10)
	{
		pUserArr = new CUser[size];
		mSize = size;
		mIndex = 0;//�û���������
	}
	~CUserDB()
	{
		delete[]pUserArr;
		pUserArr = NULL;
	}
	// ����û���Ϣ
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
	int checkUser(char *name, char *pwd)// ����û���¼Ȩ��
	{
		return AUTH_STUDENT;
	}

private:
	CUser *pUserArr;
	int mSize;
	int mIndex;
};
//===================�鼮��Ϣ����=======================
const int BOOK_NAME_LEN = 50;
const int BOOK_NUM = 100;
// �鼮���Ͷ���
class CBook
{
public:
	int getISBN() { return mISBN; }
private:
	int mISBN;//���
	char mName[BOOK_NAME_LEN];
	int mAmount;//����
};

// �鼮��DB����
class CBookDB
{
public:
	// ����鼮
	void addBook(const CBook &book)
	{
		mBookArr[mIndex++] = book;
	}
	// ɾ���鼮
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
					cur[j]=mBookArr[j];// �����i��ɾ��
				}
			}
		}
	}
	// �����鼮����
	void updateBookNumber(int isbn, int amount);
	CBook* queryBook(char *name) { return NULL; }
private:
	//CLink mBookLink; // int  CBook
	CBook mBookArr[BOOK_NUM];
	int mIndex;
};
//====================������Ϣ����=====================
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
	// ���һ��������Ϣ
	void addLoan() {}
	void queryStudentLoanInfo(char *username) {}
private:
	CLoan mLoan[LOAN_INFO_SIZE];
	int mIndex;
};
//===================������======================
class CMenu
{
public:
	CMenu()
	{
		// Ԥ��д����
	mUserDB.addUser(CUser(1000, "zhang san", 20, "��", "111", AUTH_STUDENT));
	}
	void loginMenu()
	{
		int choice;
		for (;;)
		{
			cout << "�û���:";
			gets_s(mLoginUser);  // scanf   zhang san
			cout << "����:";
			char pwd[20];
			gets_s(pwd);
			// ����û���¼�Ƿ�ɹ�
			int auth = mUserDB.checkUser(mLoginUser, pwd);
			{
				for (int i = 0;i < mIndex;i++)
					if (pUserArr[i].getName() = mLoginUser)
						cout << "chenggong";
			}
			if (auth != AUTH_INVLAID)
			{
				// ������Ӧ�����˵�
				if (auth == AUTH_STUDENT) // ����ѧ�����˵�
				{
					studentMenu();
				}
				else // �������Ա���˵�
				{
					// managerMenu();
					/*
					1. ��ѯ�鼮
					2. ����    ѧ����  �鼮�� ����ʱ��  ����ʱ�� CLoan => CLoanDB CBookDB
					3. ����
					4. ��ѯ������ʷ CLoanDB => CLoan
					*/
				}
			}
			else
			{
				cout << "�û������������!��������..." << endl;
			}
		}
	}
	//ѧ���������˵�
	void studentMenu()
	{
		cout << "============" << endl;
		cout << "1.��ѯ�鼮" << endl;
		cout << "2.�ѽ����鼮" << endl;
		cout << "============" << endl;
		cout << "ѡ��:";
		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "�������鼮������:";
			char name[20];
			gets_s(name);
			CBook *book = mBookDB.queryBook(name);

			if (book == NULL)
			{
				cout << name << " ���鼮�����ڣ�" << endl;
			}
			else
			{
				// �鵽�Ժ󣬴�ӡ�鼮����Ϣ
			}
		}

		break;
		case 2:
			// ��ѯ������Ϣ���кܶ࣬һ�ν��д�ӡ
			mLoanDB.queryStudentLoanInfo(mLoginUser);
			break;
		default:
			cout << "������Ч��������ѡ��..." << endl;
		}
	}
private:
	CUserDB mUserDB; // ��Ա��Ϣ���ݿ�
	CBookDB mBookDB; // �鼮��Ϣ���ݿ�
	CLoanDB mLoanDB; // ������Ϣ���ݿ�
	char mLoginUser[NAME_LEN]; // ��¼��ǰ��¼���û���
}; //464-244=220  300
   /*
   �����  CMenu
   ���ݲ�  CBookDB
   */
int main()
{
	CMenu menu;
	menu.loginMenu();
	return 0;
}

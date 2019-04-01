#include<iostream>
using namespace std;
class CDate
{
public:
	CDate(int y, int m, int d)
	{
		mYear = y;
		mMonth = m;
		mDay = d;
	}
private:
	int mYear;
	int mMonth;
	int mDay;
};

class CBook
{
public:
	CBook(char *n, int a, double p, int y, int m, int d):mdate(y,m,d)
	{
		if (n != NULL)
		{
			mpName = new char[strlen(n) + 1];
			strcpy_s(mpName, strlen(n) + 1, n);
		}
		else
		{
			mpName = new char[1];
			*mpName = 0;
		}

		mAmount = a;
		mPrice = p;
	}
	~CBook()
	{
		delete[]mpName;
		mpName = NULL;
	}
	void show()
	{
		cout << "name:" << mpName << endl;
		cout << "amount:" << mAmount << endl;
		cout << "price:" << mPrice << endl;
	}
private:
	char *mpName;
	double mPrice;
	int mAmount;
	CDate mdate; // 成员对象

	CBook(const CBook&);
	CBook& operator=(const CBook&);
};
int main()
{
	CBook book1("30天精通C++", 200, 100.0, 2012, 10, 1);
	book1.show();

	return 0;
}
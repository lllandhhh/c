#include<iostream>
using namespace std;

class CString
{
public:
	CString(char *p = NULL)
	{
		_pstr = new char[strlen(p)+1];
		strcpy_s(_pstr, strlen(p) + 1, p);
	}
	~CString()
	{
		delete[]_pstr;
		_pstr = NULL;
	}

	class iterator
	{
	public:
		iterator(char *p):m_top(p)
		{

		}
		bool operator !=(const iterator &it)
		{
			return  m_top != it.m_top;
		}
		void  operator++()
		{
			m_top++;
		}
		char &operator *()
		{
			return *m_top;
		}
	private:
		char  *m_top;
	};
	iterator  begin()
	{
		return iterator(_pstr);
	}
	iterator end()
	{
		return  iterator(_pstr + length());
	}
	
	CString(const CString &src)
	{
		_pstr = new char [strlen(src._pstr) + 1];
		strcpy_s(_pstr, strlen(src._pstr) + 1,src._pstr);
	}
	CString& operator=(const CString &src)
	{
		if (&src == this)
		{
			return *this;
		}
		else
		{
			delete[]_pstr;
			_pstr = new char[strlen(src._pstr) + 1];
			strcpy_s(_pstr, strlen(src._pstr) + 1,src._pstr);
		}
	}

	bool operator>(const CString &src)const
	{
		return(strcmp(_pstr, src._pstr) > 0);
	}
	bool operator<(const CString &src)const
	{
		return(strcmp(_pstr, src._pstr) < 0);
	}
	bool operator==(const CString &src)const
	{
		return(strcmp(_pstr, src._pstr) == 0);
	}
	
	int length()const
	{
		return (strlen(_pstr));
	}
	char operator[](int index)const;
	const char* c_str()const;
private:
	char *_pstr;
};
CString operator+(const CString &lhs, const CString &rhs);
ostream& operator<<(ostream &out, const CString &str);
int main()
{
	//CString str1 = "aaa";
	//CString str2 = str1;
	//CString str3;
	//str3 = str1;
	//CString str4 = str1 + str3;
	//str4 = str1 + "bbb";
	//str4 = "ccc" + str1;
	//cout << str4 << endl;

	//if (str4 > str1)
	//{
	//	cout << "str4 > str1" << endl;
	//}
	//else
	//{
	//	cout << "str4 < str1" << endl;
	//}

	//int len = str4.length();
	//for (int i = 0; i < len; i++)
	//{
	//	//str4.operator[](int index);
	//		cout << str4[i] << " ";
	//}
	//cout << endl;

	//// string   char[]
	//char buf[1024] = { 0 };
	//strcpy_s(buf , strlen(str4.c_str()) + 1,str4.c_str());
	//cout << "buf:" << buf << endl;

	CString str5 = "hello wrold";
	CString::iterator it = str5.begin();
	for (;it != str5.end();++it);
	{
		cout << *it << " ";
	}
	getchar();
	getchar();
	return 0;
}

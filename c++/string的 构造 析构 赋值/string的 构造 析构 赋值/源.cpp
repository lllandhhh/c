#include<iostream>
#include<cstring>
using namespace std;

class String
{
public:
	String(const char *str = NULL);// ��ͨ����  ������Ĭ��ֵֻ�ܳ���һ�Σ�
	String(const String &other);//�������캯��
	~String(void)
	{
		delete[]m_data;
		m_data = NULL;
	}
	String & operator=(const String &other);
private:
	char *m_data;
};

String::String(const char * str)
{
	if (str != NULL)
	{
	m_data = new char[strlen(str) + 1];
	strcpy_s(m_data, strlen(str) + 1, str);
}
else 
{
	m_data = new char[1];
	m_data = '\0';
}
}

String::String(const String & other)//other ��ԭ���� ����
{
	m_data = new char[strlen(other .m_data) + 1];
	strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
}

String & String::operator=(const String & other)
{
	if (this == &other)
		return *this;
	// TODO: �ڴ˴����� return ���
	delete[]m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
	return *this;
}
int main()
{
	string str1 = ("hello");
	string str2 = str1;
	return 0;
}
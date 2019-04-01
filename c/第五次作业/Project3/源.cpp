//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 1;              //整型 i
//	if (i == 0)

//	float j = 0;           //float j
//	if ( (-0.000001<=j && j<=0.000001)      //判别是否为0， 这是逼近0.
/
//	}
//	int t = 1;
//	int* p = &t;           //指针p
//	if (NULL == p)          //指针p是否为空




//#include<iostream>
//#include<assert.h>
//using namespace std;
//int hownumber(char *a)
//{
//	int m = 0;
//	char *one;
//	one = a;
//	char *two;
//	two = a;
//	two++;
//	while (*two != '\0')
//	{
//		if ((*one != ' ') && (*two == ' '))
//			m++;
//		one++;
//		two++;
//	}
//	if ((*two == '\0') && (*one != ' '))
//		m++;
//	return m;
//}
//int main()
//{
//	char *q = "ABC de f ";
//	cout << hownumber(q);
//	int c;
//	cin >> c;
//	return 0;
//}


//1.const 定义的常数是变量 也带类型//int float ， #define 定义的只是个常数 不带类型。
//2.define是在编译的预处理阶段起作用，而const是在 编译、运行的时候起作用。
//3.const不能重定义，而#define可以通过#undef取消某个符号的定义，再重新定义。
//4.define只是简单的字符串替换  const有对应的数据类型
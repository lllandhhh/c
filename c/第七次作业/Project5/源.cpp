//#include<iostream>
//using namespace std;
//#define p 10
//void yanghui(int(*brr)[10])
//{
//	int j;
//	int i = 0;
//	for (i = 0;i < p;i++)
//	{
//
//		for (j = 0;j < p;j++)
//		{
//			brr[i][j] = 1;
//			if (j > i)brr[i][j] = 0;
//		}
//	}
//	i = 1;j = 1;
//	for (i = 1;i < p;i++)
//	{
//		for (j = 1;j < p;j++)
//		{
//			if (i > j)
//			{
//				brr[i][j] = brr[i - 1][j - 1] + brr[i - 1][j];
//			}
//		}
//	}
//}
//			
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a[10][10] = {};
//	yanghui(a);
//	for (i=0;i < p;i++) 
//	{
//		for (j=0;j < i+1;j++)
//		{
//		cout << a[i][j]<<"  ";
//		}
//		cout << endl;
//	}
//	cin >> i;
//	return 0;
//}

//2.
//
//#include<iostream>
//using namespace std;
//#define p 3
//void mofang(int(*brr)[3])
//{
//	int m = 1;int i = 0;int j = 1;int n = 0;
//	brr[i][j] = m;
//	for (n;n < 8;n++)
//	{
//		m++;
//		i--, j++;
//		if (i == -1) { i = i + 3; }
//		if (j == 3) { j = j - 3; }
//		if (brr[i][j] == 0) { brr[i][j] = m; }
//		else
//		{
//			i++;j--;
//			if (j == -1) { j = j + 3; }
//			if (i == 3) { i = i - 3; }
//			i++;
//			if(i==3){ i = i - 3; }
//			brr[i][j] = m;
//		}
//	}
//}
//int main()
//{
//	int a[3][3] = { 0,0,0,0,0,0,0,0,0 };
//	int i = 0;
//	int j = 0;
//	mofang(a);
//	for (i = 0;i < p;i++)
//	{
//		for (j = 0;j< p;j++)
//		{
//			cout << a[i][j] << "  ";
//		}
//		cout << endl;
//	}
//	cin >> i;
//	return 0;
//}
//S1: welcome tulun == == = >wl tulun
//	S2 : come
//#include<iostream>
//using namespace std;
//void xiaocu(char *str, char *ste)
//{
//	char*m = str;
//	char*n = ste;
//	while (*n != '\0')
//	{
//		m = str;
//		while (*m != '\0')
//		{
//			if (*m == *n)
//			{
//				*m = ' ';
//			}
//			m++;
//		}
//		n++;
//	}
//	m = str;
//		while (*m!= '\0')
//	{
//		if (*m!= ' ')
//			cout << *m;
//		 m++;
//	}
//}
//int main()
//{
//	char a[] = " welcome tulun";
//	char b[] = "come";
//	xiaocu(a, b);
//	int i;
//	cin >> i;
//	return 0;
//}
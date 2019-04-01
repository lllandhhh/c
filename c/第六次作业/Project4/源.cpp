//1.
//#include<iostream>
//using namespace std;
//char  FirstNotRepeate(char* str)
//{
//	char *m = str;
//	char *n=str;
//	while (*m != '\0')
//	{
//		n = str;
//		for (n;;n++) 
//		{
//			if ((*m==*n)&&(m!=n))
//			{
//				m++;
//				break;
//			}
//			if (*n=='\0') 
//			{
//				
//				cout << *m;
//				m++;
//				break;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char a[] = "abacbd";
//	FirstNotRepeate(a);
//	return 0;
//}
//2.
//#include<iostream>
//using namespace std;
//char *Left_Arry(char *str, int num)
//{
//	int a = 0;
//	char *u = str;
//	while (*u!= '\0')
//	{
//		u++;
//		a++;
//	}
//	char *n = str;
//	char *m = str + num-1;
//	
//	while (m>n )
//	{
//		char sum = 0;
//		sum = *n;
//		*n = *m;
//		*m = sum;
//		n++;m--;
//	}
//n = str+num;
//m = str +a-1;
//	while (m >n)
//	{
//		char sum = 0;
//		sum = *n;
//		*n = *m;
//		*m = sum;
//		n++;m--;
//	}
//n = str ;
//m = str + a - 1;
//	while (m>n)
//	{
//		char sum = 0;
//		sum = *n;
//		*n = *m;
//		*m = sum;
//		n++;m--;
//	}
//	cout << str;
//	return 0;
//}
//int main()
//{
//	char a[] = "abcdef";
//	Left_Arry(a, 2);
//	int i;
//	cin >> i;
//	return 0;
//}
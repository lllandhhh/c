#include <stdio.h>
void Compress(char *str)
{
	int  i = 1;int q = 1;
	while (str[i] != '\0')
	{

		if (str[i - 1] == str[i])i++,  q++;
		else
		{
			printf("%c%d", str[i],q);
			q = 1;
			i++;
		}
}
}
	
int main()
{
	char *a = "aabbbccc";
	Compress(a);
	getchar();
	return 0;
}
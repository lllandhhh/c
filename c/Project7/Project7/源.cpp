
#include "stdio.h"
void main()
{
	char *str;
	int i, num = 0;
	scanf_s("%s", &str);
	for (i = 0;str[i] != '\0';i++)
	{
		if (str[i] >= 'A')
		{
			if (str[i] <= 'Z')
			{
				num++;
			}
		}
		
			if (str[i] >= 'a')
			{
				if (str[i] <= 'z')
				{
					num++;
				}
			}
	}
	printf("there are %d word in the line.\n", num);
}
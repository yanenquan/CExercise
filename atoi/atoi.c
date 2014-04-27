#include <stdio.h>

int atoi(const char *s)
{
	char *p = s;
	char c;
	int result = 0;
	while(c = *p++)
	{
		if((c >= '0') && (c <= '9'))
		{
			result = result*10 + (c - '0');
		}
		else
			return -1; //Invalid   string
	}
	return result;
} 


int main()
{
	char *str1 = "1234";
	printf("%d\n",atoi(str1));
	return 0;
} 

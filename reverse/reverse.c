/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 字符串反转
*  date: 2014-04-19
*  other: 无
******************************************************************************/

#include <stdio.h>

char *revstr(char *str, size_t len)
{

    char *start = str;
    char *end = str + len - 1;
    char ch;

    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}


int main()
{
	char dest[10] = "hello";
	printf("%s\n",revstr(dest,strlen(dest)));
	return 0;
}

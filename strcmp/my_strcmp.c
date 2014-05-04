/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 字符串比较
*  date: 2014-04-24
*  other: 无
******************************************************************************/

#include <stdio.h>
#include <assert.h>

int my_strcmp(const char *str1, const char *str2)
{
   assert((NULL != str1) && (NULL != str2));
   while (*str1 && *str2 && (*str1 == *str2))
   {
		str1++;
        str2++;
   }
   
   /*如果str1 > str2,则返回值大于0，如果str1 = str2,则返回值等于0，如果str1  < str2 ,则返回值小于0。*/
   return *str1 - *str2;
   
}

int main()
{
	char* str1 = "hellojava";
	char* str2 = "hello";
	printf("%d\n",my_strcmp(str1,str2));
	return 0;
} 

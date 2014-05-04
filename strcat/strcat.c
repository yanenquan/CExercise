/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 字符串连接
*  date: 2014-05-04
*  other: 无
******************************************************************************/
#include <stdio.h>
#include <assert.h>

char* strcat(char* strDest, const char* strSrc)
{
   char *rem = strDest;
   while(*strDest) strDest++;
   
   while(*strDest++=*strSrc++)
        ;
   
   return rem;
}


int main()
{
	char dest[10] = "";
	char *src = "hello";
	printf("%s\n",strcat(dest,src));
	return 0;
}

/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 宏调试
*  date: 2014-05-22
*  other: 无
******************************************************************************/
#include <stdio.h>
#include <assert.h>

//#define DEBUG_SWITCH 0 /*any num is the same, if use debug, uncomment this line*/
#ifdef DEBUG_SWITCH
	#define pr_debug(fmt,args...) printf(fmt, ##args)
#else
	#define pr_debug(fmt,args...) /*do nothing */
#endif

int main()
{
	char *str = "hello";
	pr_debug("%s\n",str);
	return 0;
}

/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 函数指针
*  date: 2014-04-02
*  other: 无
******************************************************************************/

#include <iostream>
using namespace std;

typedef void(*Fun)(int,int); //定义函数指针类型

void min(int a,int b);
void max(int a,int b);

void min(int a,int b)
{   int minvalue=a<b?a:b;
    std::cout<<"min value is "<<minvalue<<"\n";
}

void max(int a,int b)
{   int maxvalue=a>b?a:b;
    std::cout<<"Max value is "<<maxvalue<<"\n";
}

int main()
{   Fun pFun=NULL;	//定义函数指针变量pFun

    //pFun=min;		//两种赋值方式都支持
    pFun=&min;
    pFun(1,2);		//这里获得最小值

    //pFun=max;
    pFun=&max;
    pFun(1,2);		//这里获得最大值

    return 0;
} 

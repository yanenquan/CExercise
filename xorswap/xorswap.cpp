/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 异或交换
*  date: 2014-04-28
*  other: 无
******************************************************************************/

#include <iostream>    
using namespace std;   

//交换二者
void Swap(int &a, int &b) 
{  
	a = a^b;
    b = a^b;
    a = a^b;
}  

int main()
{
	int a = 8;
	int b = 9;
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	Swap(a,b);
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	return 0;
}

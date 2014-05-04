/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 冒泡排序
*  date: 2014-03-18
*  other: 无
******************************************************************************/

#include <iostream>    
using namespace std;   

//交换二者
void Swap(int &a, int &b) 
{  
	int temp = a;  
	a = b;  
	b = temp;  
}  

//打印数组
void PrintArray(int arr[],int n){   
	for(int i =0;i<n-1;i++){    
		cout<<arr[i]<<",";    
	}    
	cout<<arr[n-1]<<endl;    
}    

//冒泡排序1  
void bubbleSort1(int a[], int n)  
{  
	int i, j;  
	for (i = 0; i < n; i++)  
	{
		for (j = 1; j < n - i; j++)  
		{
			if (a[j - 1] > a[j])  
			{
				Swap(a[j - 1], a[j]);  
			}
		}
	}
} 

//冒泡排序2  
void bubbleSort2(int a[], int n)  
{  
	int i, j;  
	bool isOk = false;
	for (i = 0; i < n && !isOk; i++)  
	{
		isOk = true;
		for (j = 1; j < n - i; j++)  
		{
			if (a[j - 1] > a[j])  
			{
				Swap(a[j - 1], a[j]);  
				isOk = false;
			}
		}
	}
} 

int main()
{
	int a[] = {6,9,4,1,7,5,3};
	PrintArray(a,7);
	bubbleSort1(a,7);
	PrintArray(a,7);
	cout<<endl;

	int b[] = {6,9,4,1,7,5,3};
	PrintArray(b,7);
	bubbleSort2(b,7);
	PrintArray(a,7);
	cout<<endl;
}

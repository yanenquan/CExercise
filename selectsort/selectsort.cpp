/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 选择排序
*  date: 2014-04-20
*  other: 无
******************************************************************************/

#include <iostream>    
using namespace std;   

//打印数组
void PrintArray(int arr[],int n){   
	for(int i =0;i<n-1;i++){    
		cout<<arr[i]<<",";    
	}    
	cout<<arr[n-1]<<endl;    
}    

//交换二者
void Swap(int &a, int &b) 
{  
	int temp = a;  
	a = b;  
	b = temp;  
}  
void selectsort(int a[], int n)  
{  
	int i, j, nMinIndex;  
	for (i = 0; i < n; i++)  
	{  
		nMinIndex = i; //找最小元素的位置  
		for (j = i + 1; j < n; j++)  
			if (a[j] < a[nMinIndex])  
				nMinIndex = j;
		Swap(a[i], a[nMinIndex]); //将这个元素放到无序区的开头 
	}  
}  


int main()
{
	int a[] = {6,9,4,1,7,5,3};
	PrintArray(a,7);
	selectsort(a,7);
	PrintArray(a,7);
	cout<<endl;
}

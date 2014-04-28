#include <iostream>    
using namespace std;   

//打印数组
void PrintArray(int arr[],int n){   
	for(int i =0;i<n-1;i++){    
		cout<<arr[i]<<",";    
	}    
	cout<<arr[n-1]<<endl;    
}    

void Insertsort1(int a[], int n)  
{  
	int i, j, k;  
	for (i = 1; i < n; i++)  
	{  
		//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置  
		for (j = i - 1; j >= 0; j--)  
			if (a[j] < a[i])  
				break;  

		//如找到了一个合适的位置  
		if (j != i - 1)  
		{  
			//将比a[i]大的数据向后移  
			int temp = a[i];  
			for (k = i - 1; k > j; k--)  
				a[k + 1] = a[k];  
			//将a[i]放到正确位置上  
			a[k + 1] = temp;  
		}
	}  
}  

int main()
{
	int a[] = {6,9,4,1,7,5,3};
	PrintArray(a,7);
	Insertsort1(a,7);
	PrintArray(a,7);
	cout<<endl;
}
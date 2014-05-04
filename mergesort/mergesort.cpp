/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 合并排序
*  date: 2014-04-11
*  other: 无
******************************************************************************/

#include <iostream>  
using namespace std;  

template <class T>   
void show(T arr,int n){  
	
    for(int i =0;i<n-1;i++)
	{  
        cout<<arr[i]<<",";  
    }  
	
    cout<<arr[n-1]<<endl;  
} 

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */  
void Merge(int SR[],int TR[],int i,int m,int n)  
{  
	int j,k,l;  
	
	/* 将SR中记录由小到大归并入TR */
	for(j=m+1,k=i;i<=m && j<=n;k++)   
	{  
		if(SR[i]<SR[j])
		{
			TR[k]=SR[i++]; 
		}
		else  
		{
			TR[k]=SR[j++];  
		}
	}  
	
	/* 将剩余的SR[i..m]复制到TR */  
	if(i<=m)
	{  
		for(l=0;l<=m-i;l++) 
		{
		    TR[k+l]=SR[i+l]; 
		}
	}  
	
	/* 将剩余的SR[j..n]复制到TR */  
	if(j<=n)  
	{  
		for(l=0;l<=n-j;l++)
		{
		    TR[k+l]=SR[j+l]; 
		}
	}  
}

void MSort(int SR[],int TR1[],int s, int t)  
{  
	int m;  
	int TR2[10];  
	if(s==t) 
	{
		TR1[s]=SR[s];  
	}
	else  
	{  
		m=(s+t)/2; /* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */  
		MSort(SR,TR2,s,m);/*递归将SR[s..m]归并为有序的TR2[s..m]*/  
		MSort(SR,TR2,m+1,t);/*递归将SR[m+1..t]归并为有序TR2[m+1..t]*/  
		Merge(TR2,TR1,s,m,t);/*将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]*/  
	} 
} 

int main()  
{  
    int inputNumber[]={2,7,5,9,1,4,6,3,8}; 
    int inputNumber2[]={0,0,0,0,0,0,0,0,0};
    int count = 9; 
    show(inputNumber,10);
    MSort(inputNumber,inputNumber2,0,9); 
    show(inputNumber2,9); 
	return 0;
}  

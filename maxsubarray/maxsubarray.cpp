/*
* 连续子数组最大和		
*/

#include <iostream>    
using namespace std;   

int maxSum(int* a, int n)  
{  
    int sum = 0;  
    
    int b = 0;  
      
    for(int i=0; i<n; i++)  
    {  
        if(b < 0)           //...  
            b = a[i];  
        else  
            b += a[i];  
        if(sum < b)  
            sum = b;  
    }  
    return sum;  
}  
  
int main()  
{  
    int a[8]={1, -2, 3, 10, -4, 7, 2, -5};  
    //int a[]={-1,-2,-3,-4};  //测试全是负数的用例  
    cout<<maxSum(a,8)<<endl;  
    return 0;  
} 

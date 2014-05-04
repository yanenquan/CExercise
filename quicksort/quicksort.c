/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 快速排序
*  date: 2014-04-18
*  other: 无
******************************************************************************/

#include <stdio.h>

void quicksort (int left, int right, int a[])
{
	if(left>=right)
	{
		return;
	}
	
	int i=left, j=right;
	int key=a[i];
	
	while (i<j)
	{
		while (i<j && a[j]>=key)
			j--;
		a[i] = a[j];
		while (i<j && a[i]<=key)
			i++;
		a[j] = a[i];
	}
	
	a[i] = key;
	quicksort(left, i-1, a);
	quicksort(i+1, right, a);
}

int main ()
{
	int a[10] = {23, 12, 56, 34, 7, 9, 45, 67, 1, 6};

	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	
	quicksort(0, 9, a);
	
	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}

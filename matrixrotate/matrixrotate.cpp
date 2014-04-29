#include<iostream>
#include<cmath>

using namespace std;

/*
void rotate(int matrix[3][3], int n) 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < (n/2); i++) {
		for (j = 0; j < ceil(((double) n) / 2); j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = temp;
		}
	}
}
*/

void rotate(int *matrix, int n) 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < (n/2); i++) {
		for (j = 0; j < ceil(((double) n) / 2); j++) {
			int temp = *(matrix + i*n + j);
			*(matrix + i*n + j) = *(matrix + (n-1-j)*n + i);
			*(matrix + (n-1-j)*n + i) = *(matrix + (n-1-i)*n + (n-1-j));
			*(matrix + (n-1-i)*n + (n-1-j)) = *(matrix + j*n + (n-1-i));
			*(matrix + j*n + (n-1-i)) = temp;
		}
	}
}

int main()
{
	//int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n = 4;
	int i = 0;
	int j = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	rotate(&a[0][0],n);
	
	cout<<endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}


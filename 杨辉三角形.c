#include <stdio.h>

int main()
{
	int arr[10][11] = {0,1};
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<=1+i; j++)
		{
			arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for(int i=0; i<10; i++)
	{
		for(int j=1; j<=1+i; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

#include <stdio.h>

int main()
{
	int n = 0;
	printf("请输入数组的阶数：");
	scanf("%d",&n);
	int arr[n][n],val=1;
	arr[n/2][n/2] = n*n;
	for(int i=0; i<n/2; i++)
	{
		for(int j=i; j<n-i-1; j++)
		{
			arr[i][j] = val++;
		}
		for(int j=i; j<n-i-1; j++)
		{
			arr[j][n-i-1] = val++;
		}
		for(int j=n-i-1; j>i; j--)
		{
			arr[n-i-1][j] = val++;
		}
		for(int j=n-i-1; j>i; j--)
		{
			arr[j][i] = val++;
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
}

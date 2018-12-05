#include <stdio.h>

int main()
{
	int n = 0;
	printf("请输入数组的阶数：");
	scanf("%d",&n);
	int arr[n][n],val=1;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(i%2)
			{
				arr[j][i-j] = val++;
			}
			else
			{
				arr[i-j][j] = val++;
			}
		}
	}

	for(int i=n; i<n*2-1; i++)
	{
		for(int j=1; j<n*2-i; j++)
		{
			if(i%2)
			{
				arr[i-n+j][n-j] = val++;
			}
			else
			{
				arr[n-j][i-n+j] = val++;
			}
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


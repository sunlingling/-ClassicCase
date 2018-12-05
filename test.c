#include <stdio.h>

int main()
{
	unsigned char m = 0 , n = 0 , nonzero_count = 0 , geq_avg_count = 0;
	float sum = 0 , avg = 0;
	printf("请输入m、n的值(1<=m<=6,1<=n<=6):");
	scanf("%hhu%hhu",&m,&n);
	if(m < 1 || m > 6 || n < 1 || n > 6)
	{
		printf("m或n的值非法\n");
		return -1;
	}

	float arr[m][n];
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%f",&arr[i][j]);
			if(arr[i][j])
			{
				sum += arr[i][j];
				nonzero_count++;
			}
		}
	}
	printf("所有元素的和：%f\n",sum);
	printf("非零元素的数量：%hhu\n",nonzero_count);

	avg = sum / m / n;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j] > avg)
			{
				geq_avg_count++;
			}
		}
	}
	printf("所有元素的平均值：%f\n",avg);
	printf("大于平均值元素的数量：%hhu\n",geq_avg_count);
}

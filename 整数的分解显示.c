#include <stdio.h>

int main()
{
	int arr[10] = {};
	int count = 0 , num = 0;
	printf("请输入一个整数：");
	scanf("%d",&num);

	while(num)
	{
		arr[count++] = num %10;
		num /= 10;
	}
	
	for(int i=count-1; i>=0; i--)
	{
		printf("%d ",arr[i]);
	}
}

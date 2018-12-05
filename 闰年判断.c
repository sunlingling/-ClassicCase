#include <stdio.h>

int main()
{
	int year = 0;
	printf("请输入一个年份：");
	scanf("%d",&year);

	if(!(year%4)&&year%100||!(year%400))
	{
		printf("闰年\n");
	}
	else
	{
		printf("平年\n");
	}
}
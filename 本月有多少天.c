#include <stdio.h>

int main()
{
	char month = 0;
	printf("请输入一个月份：");
	scanf("%hhd",&month);

	if(2 == month)
	{
		printf("28");
	}
	else if(4 == month || 6 == month ||
		9==month || 11==month)
	{
		printf("30");
	}
	else
	{
		printf("31");
	}
}

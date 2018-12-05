#include <stdio.h>

int main()
{
	unsigned int num = 0;
	printf("请输入一个正整数：");
	scanf("%u",&num);
	while(num)
	{
		printf("%u",num%10);
		num /= 10;
	}
}
#include <stdio.h>

int main()
{
	int num = 0;
	printf("请输入一个整数:");
	scanf("%d",&num);

	int count = 0;
	for(int i=2; i<num/2; i++)
	{
		if(0 == num%i)
		{
			count++;
		}
	}

	if(0 == count)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}
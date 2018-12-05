#include <stdio.h>

int main()
{
	float score = 0;
	printf("请输入一个成绩：");
	scanf("%f",&score);

	if(0>score || score>100)
	{
		printf("error");
	}
	else if(score < 60)
	{
		printf("E");
	}
	else if(score < 70)
	{
		printf("D");
	}
	else if(score < 80)
	{
		printf("C");
	}
	else if(score < 90)
	{
		printf("B");
	}
	else
	{
		printf("A");
	}
}

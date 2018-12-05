#include <stdio.h>

int main()
{
	int prev = 1 , curr = 0 , next = 0 , n = 0;
	printf("请输入n：");
	scanf("%d",&n);
loop:
	next = prev + curr;
	printf("%d ",next);
	prev = curr;
	curr = next;
	if(n-- > 1)
	{
		goto loop;
	}
}
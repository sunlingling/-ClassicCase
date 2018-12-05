#include <stdio.h>

int main()
{
	for(int i=100; i<1000; i++)
	{
		int count = 0;
		for(int j=2; j<i/2; j++)
		{
			if(0 == i%j)
			{
				count++;
			}
		}
		if(0 == count)
		{
			printf("%d ",i);
		}
	}
}

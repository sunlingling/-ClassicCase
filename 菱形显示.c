#include <stdio.h>
#include <stdlib.h>

int main()
{
	for(int i=-4; i<5; i++)
	{
		for(int j=0; j<abs(i); j++)
		{
			printf(" ");
		}
		for(int j=0; j<(5-abs(i))*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
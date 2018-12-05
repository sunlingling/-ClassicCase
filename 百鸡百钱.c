#include <stdio.h>

int main()
{
	for(int i=0; i<=20; i++)
	{
		for(int j=0; j<34; j++)
		{
			float k = 100 - i - j;
			if(100 == i*5+j*3+k/3)
			{
				printf("公:%d 母:%d 小:%g\n",i,j,k);
			}
		}
	}
}

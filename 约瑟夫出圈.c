#include <stdio.h>

int main()
{
	int arr[41] = {} , count = 41 , index = 0 , step = 0;
	while(count>2)
	{
		if(0 == arr[index%41])
		{
			step++;
		}
		if(3 == step)
		{
			arr[index%41] = 1;
			step = 0;
			count--;
		}
		index++;
	}

	for(int i=0; i<41; i++)
	{
		if(0 == arr[i])
		{
			printf("%d\n",i+1);
		}
	}
}

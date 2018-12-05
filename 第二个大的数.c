#include <stdio.h>

int main()
{
	int arr[10] = {10,1,9,7,2,5,4,3,0,6};
	int max=arr[0],two_max=0;

	for(int i=1; i<10; i++)
	{
		if(max < arr[i])
		{
			two_max = max;
			max = arr[i];
		}	
		else if(two_max < arr[i])
		{
			two_max = arr[i];
		}
	}
	printf("%d\n",two_max);
}

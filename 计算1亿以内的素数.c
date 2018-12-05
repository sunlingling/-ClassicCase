#include <stdio.h>
#include <math.h>

//5761455
int arr[100000000] = {1,1};
int main()
{
	int count = 0;
	for(int i=2; i<=10000; i++)
	{
		for(int j=i+i; j<100000000; j+=i)
		{
			arr[j] = 1;
		}
	}
	for(int i=1; i<100000000; i+=2)
	{
		if(arr[i] < 1) count++;
	}
	printf("%d\n",count);
}

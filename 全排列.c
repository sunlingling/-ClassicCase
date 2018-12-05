#include <stdio.h>

#define swap(v1,v2) {typeof(v1) t=v1;v1=v2;v2=t;}

void array(int arr[],int start_i,int end_i)
{
	if(start_i >= end_i)
	{
		//此处是排列好的结果	
		for(int i=0; i<end_i; i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		array(arr,start_i+1,end_i);
		for(int i=start_i+1; i<end_i; i++)
		{
			swap(arr[start_i],arr[i]);
			array(arr,start_i+1,end_i);
			swap(arr[start_i],arr[i]);
		}
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	array(arr,0,sizeof(arr)/sizeof(arr[0]));
}

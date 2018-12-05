#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM 21

int main()
{
	srand(time(NULL));
	system("clear");
	char* arr[20] = {"计佳诚", "李攀力", "段朝勃","朱兆欢","牧云杰","叶德熙", "沈煜炀","任西平","郭　磊","尹佳怡","王浩林","王曦文","范焱文","许　可","宓琦超", "周仁杰", "林德龙","成天晓","谢　申","何　梁"};

	for(int i=0; i<20;)
	{
		int index = rand()%20;
		if(arr[index])
		{
			printf("第 %2d 次演讲着: %s\n", ++i,arr[index]);
			arr[index] = NULL;
		}
	}

	return 0;
}


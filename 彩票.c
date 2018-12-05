#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool check_num(char num,char red[6])
{
	for(char i=0; i<6; i++)
	{
		if(num == red[i])
		{
			return false;
		}
	}

	return true;
}


int main()
{
	srand(time(NULL));

	char red[6] = {};
	char count = 0;
	while(count < 6)
	{
		char num = rand()%33+1;
		if(check_num(num,red))
		{
			red[count++] = num;
		}
	}

	for(char i=0; i<6; i++)
	{
		printf("%d ",red[i]);
	}

	printf("%d\n",rand()%16+1);

}

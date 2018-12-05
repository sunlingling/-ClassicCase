#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <getch.h>

char* get_passwd(char* pass,size_t len,bool is_show)
{
	if(NULL == pass) return NULL;
	int index = 0;
	do{
		pass[index] = getch();
		if(127 == pass[index])
		{
			if(index > 0)
			{
				index--;
				if(is_show)
				{
					printf("\b \b");
				}
			}
			continue;
		}
		else if(10 == pass[index])
		{
			printf("\n");
			break;
		}
		else if(is_show)
		{
			printf("*");
		}
		index++;
	}while(index < len -1);
	
	pass[index] = '\0';

	return pass;
}

int main()
{
	char pass[20] = {};
	printf("请输入密码：");
	get_passwd(pass,20,0);
	if(0 == strcmp("zzxx",pass))
	{
		puts("登录成功!");
	}
	else
	{
		puts("密码错误!");
	}
}

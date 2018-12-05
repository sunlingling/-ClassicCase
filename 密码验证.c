#include <stdio.h>

int main()
{
	int pass = 0;
	int count = 0;
	do{
		if(0 == count)
		{
			printf("请输入密码：");
		}
		else
		{
			printf("密码错误，请重新输入(还有%d次机会)：",3-count);
		}
		scanf("%d",&pass);

	}while(count++<2 && pass!=132466);

	if(132466 == pass)
	{
		printf("登录成功!\n");
	}
	else
	{
		printf("帐号锁定，请申诉！\n");
	}
}
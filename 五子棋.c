#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 定义棋盘数组
	char board[15][15];
	// 定义角色
	char role = '@';
	// 定义棋子坐标
	char key_x = -1 , key_y = -1;
	// 统计相同棋子的数量
	char count = 0;

	// 初始化棋盘 全部设置为'*'
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			board[i][j] = '*';
		}
	}

	while(1)
	{
		// 清理屏幕
		system("clear");
		// 显示棋盘 空* 红@ 蓝#
		for(int i=0; i<15; i++)
		{
			for(int j=0; j<15; j++)
			{
				printf(" %c",board[i][j]);
			}
			printf("\n");
		}

		// 检查是否形成五子
		count = 0;
		// 左上
		for(int x=key_x-1,y=key_y-1; x>=0&&y>=0&&
			board[key_x][key_y]==board[x][y];x--,y--)
		{
			count++;
		}
		// 右下
		for(int x=key_x+1,y=key_y+1; x<15&&y<15&&
			board[key_x][key_y]==board[x][y];x++,y++)
		{
			count++;
		}
		if(count >=4) break;

		// 切角色 如果现在是红方则切换为蓝方
		role = role=='@'?'#':'@';

		// 接收棋子坐标
		printf("请%c输入棋子坐标:",role);
		scanf("%hhd%hhd",&key_x,&key_y);

		// 检查坐标是否合法 是否已经有棋子
		if(key_x<0 || key_x>14 || 
		   key_y<0 || key_y>14)
		{
			printf("输入的坐标非法！！！\n");
			continue;
		}
		if('*'!=board[key_x][key_y])
		{
			printf("此位置已有棋子！！！\n");
			continue;
		}

		// 落子
		board[key_x][key_y] = role;
	}
	
	printf("恭喜%c胜利，游戏结束！\n",role);
}

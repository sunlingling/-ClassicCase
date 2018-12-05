#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

uint8_t mouse_y = 0;
uint8_t mouse_x = 0;
uint8_t mout_y  = 1;
uint8_t mout_x  = 8;

void show_maze();
void show_path();
void visit_out(int8_t y,int8_t x);

uint8_t maze[10][10] = 
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,0,1,0,1},
	{1,0,1,0,1,1,0,1,0,1},
	{1,0,1,0,1,1,0,1,0,1},
	{1,0,1,0,1,0,0,1,0,1},
	{1,0,1,0,1,0,1,0,0,1},
	{1,0,1,0,1,0,1,0,1,1},
	{1,0,1,0,1,0,1,0,1,1},
	{1,0,0,0,1,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1},
};

void visit_out(int8_t y,int8_t x)
{
	if(y>9 || y<0 || x>9 || x<0) return;
	
	maze[y][x] = 3;
	
	if(y == mout_y && x == mout_x)
	{
		maze[mouse_y][mouse_x] = 2;
		show_path();
	}
	
	if(0 == maze[y-1][x]) visit_out(y-1,x);
	if(0 == maze[y+1][x]) visit_out(y+1,x);
	if(0 == maze[y][x-1]) visit_out(y,x-1);
	if(0 == maze[y][x+1]) visit_out(y,x+1);
	
	maze[y][x] = 0;
}

void show_path()
{
	while(mouse_y != mout_y || mouse_x != mout_x)
	{
		if(3 == maze[mouse_y+1][mouse_x])
		{
			maze[mouse_y][mouse_x] = 0;
			mouse_y++;
			maze[mouse_y][mouse_x] = 2;
		}
		else if(3 == maze[mouse_y-1][mouse_x])
		{
			maze[mouse_y][mouse_x] = 0;
			mouse_y--;
			maze[mouse_y][mouse_x] = 2;
		}
		else if(3 == maze[mouse_y][mouse_x+1])
		{
			maze[mouse_y][mouse_x] = 0;
			mouse_x++;
			maze[mouse_y][mouse_x] = 2;
		}
		else if(3 == maze[mouse_y][mouse_x-1])
		{
			maze[mouse_y][mouse_x] = 0;
			mouse_x--;
			maze[mouse_y][mouse_x] = 2;
		}	
		show_maze();
		sleep(1);
	}
}

void show_maze()
{
	system("clear");
	for(uint8_t y=0; y<10; y++)
	{
		for(uint8_t x=0; x<10; x++)
		{
			switch(maze[y][x])
			{
				case 0:printf(" ");break;
				case 1:printf("#");break;
				case 2:printf("@");break;
				case 3:printf("*");break;
			}
		}
		printf("\n");
	}	
}

int main()
{
	srand(time(NULL));
	do
	{
		mouse_x = rand() % sizeof(maze[0])/sizeof(maze[0][0]);
		mouse_y = rand() % sizeof(maze)/sizeof(maze[0]);
	}while(maze[mouse_y][mouse_x] != 0);
	
	visit_out(mouse_y,mouse_x);
}

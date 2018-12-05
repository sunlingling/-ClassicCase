#include <stdio.h>
#include <stdbool.h>
#include "get_keyboard.h"

// 0路，#1墙，@2人,=３箱子，O4目标,@６人在目标上,=７箱子在目标上
char map[8][6] = 
{
  {0,1,1,1,1,0},
  {1,1,0,0,1,0},
  {1,2,3,0,1,0},
  {1,1,3,0,1,1},
  {1,1,0,3,0,1},
  {1,4,3,0,0,1},
  {1,4,4,0,4,1},
  {1,1,1,1,1,1},
};

// 定义推者的坐标
char man_x = 1;
char man_y = 2;
// 定义完成任务时走了多步
unsigned long step_count;
// 声明显示地图的函数
void show_map();
// 声明检查箱子的函数
bool judge_box();
// 声明人移动函数
void man_move(char dev_y,char dev_x);

int main()
{
  while(true)
  {
    // 显示地图
    show_map();
    // 判断箱子是否全部到达目标
    if(judge_box())
    {
      printf("完成任务共用了%lu步！\n",step_count);
      return 0;
    }
    // 获取方向键   
    switch(get_keyboard())
    {
      case KEY_UP: man_move(-1,0); break;
      case KEY_DOWN: man_move(1,0); break;
      case KEY_RIGHT: man_move(0,1); break;
      case KEY_LEFT: man_move(0,-1); break;
    }
  }
}

// 定义显示地图的函数
void show_map()
{
  //调用系统接口，清理屏幕
  system("clear");
  for(char y=0; y<8; y++)
  {
    for(char x=0; x<6; x++)
    {
      switch(map[y][x])
      {
        case 0: printf(" "); break;
        case 1: printf("#"); break;
        case 2: printf("@"); break;
        case 3: printf("="); break;
        case 4: printf("O"); break;
        case 6: printf("@"); break;
        case 7: printf("="); break;        
      }
    }
    printf("\n");
  }  
}

bool judge_box()
{
  char box_on_end = 0;
  for(char y=0; y<8; y++)
  {
    for(char x=0; x<6; x++)
    {
        box_on_end += 7==map[y][x];
    }
  } 
  
  return 4 == box_on_end;
}

void man_move(char dev_y,char dev_x)
{
  if(0==map[man_y+dev_y][man_x+dev_x] || 
     4==map[man_y+dev_y][man_x+dev_x])
  {
    map[man_y][man_x] -= 2;
    man_y += dev_y;
    man_x += dev_x;
    map[man_y][man_x] += 2;
    step_count++;
  }
  else if(3==map[man_y+dev_y][man_x+dev_x] || 
          7==map[man_y+dev_y][man_x+dev_x])
  {
    if(0==map[man_y+2*dev_y][man_x+2*dev_x] || 
       4==map[man_y+2*dev_y][man_x+2*dev_x])
    {
      map[man_y+dev_y][man_x+dev_x] -= 3;
      map[man_y+2*dev_y][man_x+2*dev_x] += 3;
      
      map[man_y][man_x] -= 2;
      man_y += dev_y;
      man_x += dev_x;
      map[man_y][man_x] += 2;
      step_count++;
    }
  }
}

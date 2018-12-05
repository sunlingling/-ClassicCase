#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <get_keyboard.h>

int main()
{
	int8_t cursor_x = 1;
	int8_t cursor_y = 1;

	while(true)
	{
		system("clear");
		printf("\33[2J");
		for(int8_t x=0; x<10; x++)
		{
			for(int8_t y=0; y<10; y++)
			{
				printf("*");
			}
			printf("\n");
		}

		printf("\33[%d;%dH",cursor_x,cursor_y);

		switch(get_keyboard())
		{
		case KEY_UP:
			cursor_x--;
			break;
		case KEY_DOWN:
			cursor_x++;
			break;
		case KEY_RIGHT:
			cursor_y++;
			break;
		case KEY_LEFT:
			cursor_y--;
			break;
		}
	}
}

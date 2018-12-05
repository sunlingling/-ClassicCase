#include <stdio.h>
int count;

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        move(n, a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}
void move(int n, char a, char b)
{
    count++;
    printf("第%d次移动 move %d: move from %c to %c !\n",count,n,a,b);
}

int main()
{
    int n=8;
    printf("请输入汉诺塔的层数:");
    scanf(" %d",&n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}


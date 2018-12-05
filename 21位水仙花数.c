#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define NUM_SIZE 21

uint8_t numPow[10][NUM_SIZE];
uint8_t numCnt[10];
uint8_t num[NUM_SIZE];

void init_num_pow()
{
    for(int8_t i=1; i<10; i++)
    {
        numPow[i][NUM_SIZE-1] = i;
        for(int8_t k=1; k<NUM_SIZE; k++)
        {
            uint8_t carry = 0;
            for(int8_t j=NUM_SIZE-1; j>=0; j--)
            {
                numPow[i][j] = numPow[i][j] * i + carry;
                carry = numPow[i][j] / 10;
                numPow[i][j] %= 10;
            }
        }
    }
}

void num_add(uint8_t* numArr,uint8_t cnt)
{
    uint8_t carry = 0;
    for(int8_t i=NUM_SIZE-1; i>=0; i--)
    {
        num[i] = num[i] + (numArr[i]*cnt) + carry;
        carry = num[i] / 10;
        num[i] %= 10;
    }
}

uint8_t num_cnt(uint8_t n)
{
    uint8_t cnt = 0;
    for(int8_t i=0; i<NUM_SIZE; i++)
    {
        cnt += (num[i] == n);
    }
    return cnt;
}

void gen_num()
{
    bzero(num,sizeof(num));

    for(int8_t i=0; i<10; i++)
    {
        if(NUM_SIZE-1 <= numCnt[i]) return;
        num_add(numPow[i],numCnt[i]);
    }

    for(int8_t i=0; i<10; i++)
    {
        if(numCnt[i] != num_cnt(i)) return;
    }

    for(int8_t i=0; i<NUM_SIZE; i++)
        printf("%d",num[i]);
    printf("\n");
}

void find_num(uint8_t num,int8_t cnt)
{
    if(0 == num)
    {
        numCnt[0]= cnt;
        gen_num();
        return;
    }

    for(int8_t i=0; i<=cnt; i++)
    {
        numCnt[num] = i;
        find_num(num-1,cnt-i);
    }
}

int main()
{
    init_num_pow();
    find_num(9,NUM_SIZE);
}

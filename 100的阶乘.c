#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t result[200] = {1};
    uint8_t index = 1;

    for(uint8_t num = 2; num<=100; num++)
    {
        uint16_t carry = 0;
        for(uint8_t i=0; i<index; i++)
        {
            uint16_t value = result[i] * num + carry;
            result[i] = value % 10;
            carry = value / 10;
        }

        while(carry)
        {
            result[index++] = carry % 10;
            carry /= 10;
        }
    }

    for(int16_t i=index-1; i>=0; i--)
    {
        printf("%hhu",result[i]);
    }
    printf("\n%d\n",index);
}

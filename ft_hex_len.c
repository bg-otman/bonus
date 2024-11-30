#include "libftprintf.h"

int ft_hex_len(unsigned long n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n)
    {
        n /= 16;
        len++;
    }
    return (len);
}
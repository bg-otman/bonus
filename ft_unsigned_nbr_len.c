#include "libftprintf.h"

int ft_unsigned_nbr_len(unsigned int nb)
{
    int len;

    if (nb == 0)
        return (1);
    len = 0;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}
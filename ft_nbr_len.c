#include "libftprintf.h"

int ft_nbr_len(int nb)
{
    int len;

    if (nb == 0)
        return (1);
    len = 0;
    if (nb < 0)
    {
        len++;
        nb = -nb;
    }
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}
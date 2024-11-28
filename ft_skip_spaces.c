#include "libftprintf.h"

void ft_skip_spaces(const char **str)
{
    int i;

    i = 0;
    while ((*str)[i] != '\0' && (*str)[i] == ' ')
        i++;
    *str += i;
}
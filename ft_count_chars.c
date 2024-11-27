#include "libftprintf.h"

int ft_count_chars(char c, const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] == c)
        i++;
    return (i);
}
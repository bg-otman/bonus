
#include "libftprintf.h"

void ft_skip_chars(const char **str, char c)
{
    while (**str == c)
        (*str)++;
}
#include "libftprintf.h"

int ft_putbefore(char c, const char **str, va_list args)
{
    int space_nb;
    int char_len;
    int i;
    int count;
    int specifier;

    space_nb = ft_atoi(*str);
    char_len = ft_count_chars(' ', *str);
    specifier = ft_nbr_len(space_nb) + char_len;
    i = 0;
    c = (*str)[specifier];
    count = ft_get_arglen(c, args);
    while (i < space_nb - count)
    {
        ft_putchar(' ');
        i++;
    }
    if (c != '\0')
        count = check_specifier(c, args, str);
    *str += specifier;
    return (count + i);
}

#include "libftprintf.h"

int ft_putspace_after(const char **str, va_list args)
{
    int space_nb;
    int char_len;
    int i;
    int count;
    int specifier;

    space_nb = ft_atoi(*str);
    char_len = ft_count_chars('-', *str);
    specifier = ft_nbr_len(space_nb) + char_len;
    i = 0;
    count = 0;
    while (i < specifier)
        i++;
    if ((*str)[i] != '\0')
        count = check_specifier((*str)[i], args, str);
    i = 0;
    while (i < space_nb - count)
    {
        ft_putchar(' ');
        i++;
    }
    *str += specifier;
    return (count + i);
}

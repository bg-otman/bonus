#include "libftprintf.h"


int ft_putspace_after(const char **str, va_list args)
{
    int space_nb;
    int char_len;
    int count;
    int i;

    space_nb = ft_atoi(*str);
    if (space_nb == -1)
        return (-1);
    char_len = ft_count_chars('-', *str);
    i = 0;
    while ((*str)[i] && i < ft_nbr_len(space_nb) + char_len)
        i++;
    if (is_valid_specifier((*str)[i]))
    {
        i = 0;
        count = check_specifier((*str)[i], args, str);
        while (i < space_nb - count)
        {
            ft_putchar(' ');
            i++;
        }
        *str += ft_nbr_len(space_nb) + char_len;
        return (ft_nbr_len(space_nb) + char_len);
    }
    return (ft_putchar('%') + ft_putchar('-'));
}

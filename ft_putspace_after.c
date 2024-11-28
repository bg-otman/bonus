
#include "libftprintf.h"

int     ft_putspace_after(const char **str, va_list args)
{
    int     space_nb;
    char    specifier;
    int     len;

    space_nb = ft_atoi(*str);
    if (space_nb == -1)
        return (-1);
    specifier = (*str)[ft_nbr_len(space_nb)];
    if (is_valid_specifier(specifier))
    {
        len = check_specifier(specifier, args);
        while (len < space_nb)
        {
            ft_putchar(' ');
            len++;
        }
        *str += ft_nbr_len(space_nb);
        return (len);
    }
    return (ft_putchar('%') + ft_putchar('-'));
}

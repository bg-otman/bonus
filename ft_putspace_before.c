
#include "libftprintf.h"

static int get_len(char specifier, va_list args)
{
    va_list args_copy;
    int len;

    va_copy(args_copy, args);
    len = get_arg_len(specifier, args_copy);
    va_end(args_copy);
    return (len);
}

int ft_putspace_before(const char **str, va_list args)
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
        len = get_len(specifier, args);
        if (len == -1)
            return (-1);
        while (len < space_nb)
        {
            ft_putchar(' ');
            len++;
        }
        check_specifier(specifier, args);
        *str += ft_nbr_len(space_nb);
        return (len);
    }
    return (ft_putchar('%'));
}

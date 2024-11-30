
#include "libftprintf.h"

static int check_flags(const char **str, char *c, int *minus_exist)
{
    int space_nb;

    *c = ' ';
    *minus_exist = 0;
    space_nb = ft_atoi(*str);
    if (space_nb == -1)
        return (-1);
    while (**str == ' ' || **str == '+' || **str == '-' || (**str >= '0' && **str <= '9'))
    {
        if (**str == '+')
            *c = '+';
        if (**str == '-')
            *minus_exist = 1;
        (*str)++;
    }
    return (space_nb);
}

static int handle_other(int num, char c, int space_nb)
{
    int len;

    len = 0;
    space_nb = space_nb - ft_nbr_len(num);
    if ((c == '+' && num >= 0) || (c == ' ' && num >= 0))
        space_nb--;
    while (space_nb > 0)
    {
        len += ft_putchar(' ');
        space_nb--;
    }
    if (num >= 0)
        len += ft_putchar(c);
    len += ft_putnbr(num);
    return (len);
}

static int handle_minus(int num, int space_nb, char c)
{
    int len;

    len = 0;
    if (num >= 0)
        len += ft_putchar(c);
    len += ft_putnbr(num);
    while (len < space_nb)
    {
        ft_putchar(' ');
        len++;
    }
    return (len);
}

int ft_handle_space(const char **str, va_list args)
{
    int len;
    char c;
    int num;
    int minus_exist;
    int space_nb;

    len = 0;
    space_nb = check_flags(str, &c, &minus_exist);
    if (space_nb == -1)
        return (-1);
    if (**str == 'd' || **str == 'i')
    {
        num = va_arg(args, int);
        if (minus_exist)
            len += handle_minus(num, space_nb, c);
        else
            len += handle_other(num, c, space_nb);
    }
    else
        len += handle_format(str, args);
    return (len);
}

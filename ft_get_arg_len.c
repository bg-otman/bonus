
#include "libftprintf.h"

// int get_arg_len(char specifier, va_list args)
// {
//     if (specifier == 's')
//         return (ft_strlen(va_arg(args, char *)));
//     else if (specifier == 'd' || specifier == 'i')
//         return (ft_nbr_len(va_arg(args, int)));

//     return (-1);
// }

//////////////////////
static int ft_unsigned_nbr_len(unsigned int n)
{
    int len;
    if (n == 0)
        return (1);
    len = 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}


static int ft_hex_len(unsigned long n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n)
    {
        n /= 16;
        len++;
    }
    return (len);
}

int get_arg_len(char specifier, va_list args)
{
    int len;
    unsigned long long ptr;

    if (specifier == 's')
    {
        len = ft_strlen(va_arg(args, char *));
        if (len == 0)
            return (ft_strlen("(null)"));
        return (len);
    }
    else if (specifier == 'd' || specifier == 'i')
        return (ft_nbr_len(va_arg(args, int)));
    else if (specifier == 'u')
        return (ft_unsigned_nbr_len(va_arg(args, unsigned int)));
    else if (specifier == 'x' || specifier == 'X')
        return (ft_hex_len(va_arg(args, unsigned int)));
    else if (specifier == 'p')
    {
        if (!(ptr = va_arg(args, unsigned long long)))
            return (ft_strlen("(nil)"));
        return (2 + ft_hex_len(ptr));
    }
    else if (specifier == 'c')
        return (1);
    return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:52:20 by obouizi           #+#    #+#             */
/*   Updated: 2024/11/27 11:40:42 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int handle_flags(char c, va_list args, const char **str)
{
    int len;
    
    len = 0;
    if (c == ' ')
    {
        ft_skip_spaces(str);
        c = **str;
    }
    if (c == '-')
		len = ft_putspace_after(str, args);
    else if (c == ' ' || (c >= '1' && c <= '9'))
        len = ft_putbefore(c, str, args);

    return (len);
}

int check_specifier(char c, va_list args, const char **str)
{
    int len = 0;

    if (c == 's')
        len = ft_putstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        len = ft_putnbr(va_arg(args, int));
    else if (c == 'c')
        len = ft_putchar((char)va_arg(args, int));
    else if (c == 'x')
        len = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
    else if (c == 'X')
        len = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (c == 'u')
        len = ft_putunsint(va_arg(args, unsigned int));
    else if (c == 'p')
        len = ft_putadresse(va_arg(args, unsigned long long));
    else if (c == '-' || c == ' ' || (c >= '1' && c <= '9'))
        len = handle_flags(c, args, str);
    else
    {
        len = ft_putchar('%');
    }
    return len;
}

/// / / // / / / / / 
int ft_put_percent(const char **str)
{
    ft_putchar(**str);
    (*str)++;
    return (1);
}

int handle_specifier(const char **str, va_list args)
{
    (*str)++;
    if (**str != '\0')
        return check_specifier(**str, args, str);
    return (0);
}

int ft_printf(const char *str, ...)
{
    int printlen;
    int i;
    va_list args;

    va_start(args, str);
    i = 0;
    printlen = 0;
    while (*str)
    {
        if (*str == '%' && *(str + 1) == '%')
            printlen += ft_put_percent(&str);
        else if (*str == '%' && *(str + 1) != '%')
        {
            if ((i = handle_specifier(&str, args)) == -1)
                break ;
            printlen += i;
        }
        else
            printlen += ft_putchar(*str);
        str++;
    }
    va_end(args);
    return (printlen);
}

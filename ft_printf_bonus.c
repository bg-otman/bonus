/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:52:20 by obouizi           #+#    #+#             */
/*   Updated: 2024/11/26 15:47:12 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int handle_flags(const char **str, va_list args)
{
	int len;

	len = 0;
	if (**str == '-')
	{
		ft_skip_chars(str, '-');
		len = ft_putspace_after(str, args);
	}
	else
	{
		len += ft_putchar('%');// here
		len += ft_putchar(**str);// here handle % and just spaces
	}

	return (len);
}


int	check_specifier(char c, va_list args)
{
	int len;

	len = 0;
	if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		len = ft_putchar((char) va_arg(args, int));
	else if (c == 'x')
		len = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'u')
		len = ft_putunsint((va_arg(args, unsigned int)));
	else if (c == 'p')
		len = ft_putadresse((va_arg(args, unsigned long)));
	return (len);
}
static int ft_put_percent(const char **str)
{
    ft_putchar(**str);
    (*str)++;
    return (1);
}
int handle_format(const char **str, va_list args)
{
    (*str)++;
    ft_skip_chars(str, ' ');
    if (is_valid_specifier(**str))
        return (check_specifier(**str, args));
	else
    	return (handle_flags(str, args));
}

int ft_printf(const char *str, ...)
{
    int printlen;
	int	i;
    va_list args;

    va_start(args, str);
    printlen = 0;
	i = 0;
    while (*str)
    {
        if (*str == '%' && *(str + 1) == '%')
            printlen += ft_put_percent(&str);
        else if (*str == '%' && *(str + 1) != '\0')
        {
            if ((i = handle_format(&str, args)) == -1)
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



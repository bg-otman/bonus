/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:18:56 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:22:12 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int decimal_precision(const char **str, va_list args, int width)
{
    int num;
    int len;
    int skip_width;
    
    len = 0;
    num = va_arg(args, int);
    skip_width = ft_nbr_len(width);
    if (num < 0)
    {
        len += ft_putchar('-');
        num = -num;
    }
    while (width > ft_nbr_len(num))
    {
        len += ft_putchar('0');
        width--;
    }
    if (num != 0)
        len += ft_putnbr(num);
    *str += skip_width;
    return (len);
}

static int unsigned_precision(const char **str, va_list args, int width)
{
    unsigned int num;
    int len;
    int skip_width;
    
    len = 0;
    num = va_arg(args, unsigned int);
    skip_width = ft_nbr_len(width);
    while (width > ft_unsigned_nbr_len(num))
    {
        len += ft_putchar('0');
        width--;
    }
    if (num != 0)
        len += ft_putunsint(num);
    *str += skip_width;
    return (len);
}

static int string_precision(const char **str, va_list args, int width)
{
    char *buffer;
    int len;
    int i;

    buffer = va_arg(args, char *);
    len = ft_strlen(buffer);
    if (width >= len)
    {
        *str += ft_nbr_len(width);
        return (write(1, buffer, len));
    }
    i = 0;
    while (i < width)
    {
        ft_putchar(buffer[i]);
        i++;
    }
    *str += ft_nbr_len(width);
    return (width);
}

static int hex_precision(const char **str, va_list args, int width, char *hex)
{
    unsigned int nb;
    int len;
    int skip_width;

    len = 0;
    nb = va_arg(args, unsigned int);
    skip_width = ft_nbr_len(width);
    while (width > ft_hex_len(nb))
    {
        len += ft_putchar('0');
        width--;
    }
    if (nb != 0)
        len += ft_puthex(nb, hex);
    *str += skip_width;
    return (len);

}

int handle_dot(const char **str, va_list args)
{
    int width;
    char specifier;

    (*str)++;
    width = ft_atoi(*str);
    if (width == -1)
        return (-1);
    specifier = (*str)[ft_nbr_len(width)];
    if (specifier == 'd' || specifier == 'i')
        return (decimal_precision(str, args, width));
    else if (specifier == 's')
        return (string_precision(str, args, width));
    else if (specifier == 'u')
        return (unsigned_precision(str, args, width));
    else if (specifier == 'x')
        return (hex_precision(str, args, width, "0123456789abcdef"));
    else if (specifier == 'X')
        return (hex_precision(str, args, width, "0123456789ABCDEF"));
    return (ft_putchar('%'));
}

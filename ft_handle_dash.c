/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:16:49 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:19:46 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int hex_precision(va_list args, char *hex, char upper_or_lower)
{
    unsigned int nb;
    int len;

    len = 0;
    nb = va_arg(args, unsigned int);
    if (nb != 0)
    {
        if (upper_or_lower == 'x')
            len += ft_putstr("0x");
        else
            len += ft_putstr("0X");
        len += ft_puthex(nb, hex);
    }
    else
        len = ft_putchar('0');
    return (len);

}

int handle_dash(const char **str, va_list args)
{
    (*str)++;
    if (**str == 'x')
        return (hex_precision(args, "0123456789abcdef", 'x'));
    else if (**str == 'X')
        return (hex_precision(args, "0123456789ABCDEF", 'X'));
    else
        return (check_specifier(**str, args));
}
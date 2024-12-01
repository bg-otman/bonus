/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:18:12 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:21:20 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int get_len(char specifier, va_list args, int *is_negative)
{
    va_list args_copy;
    int len;
    int num;

    *is_negative = 0;
    num = 0;
    len = 0;
    va_copy(args_copy, args);
    if (specifier == 'd' || specifier == 'i')
    {
        num = va_arg(args_copy, int);
        if (num < 0)
        {
            *is_negative = 1;
            num = -num;
        }
        len = ft_nbr_len(num);
    }
    else
        len = get_arg_len(specifier, args_copy);
    va_end(args_copy);
    return len;
}

static int print_zero(int is_negative, int space_nb, int len)
{
    if (is_negative)
    {
        ft_putchar('-');
        len++;
    }
    while (len < space_nb)
    {
        ft_putchar('0');
        len++;
    }
    return (len);
}

void print_positive(char specifier, va_list args)
{
    int num;

    num = 0;
    if (specifier == 'd' || specifier == 'i')
    {
		num = va_arg(args, int);
        num = -num;
        ft_putnbr(num);
    }
}

int ft_putzero(const char **str, va_list args)
{
    int space_nb;
    char specifier;
    int len;
    int is_negative;

    ft_skip_chars(str, '0');
    space_nb = ft_atoi(*str);
    if (space_nb == -1)
        return (-1);
    specifier = (*str)[ft_nbr_len(space_nb)];
    if (is_valid_specifier(specifier))
    {
        len = get_len(specifier, args, &is_negative);
        if (len == -1)
            return (-1);
        len = print_zero(is_negative, space_nb, len);
        if (is_negative)
            print_positive(specifier, args);
        else
            check_specifier(specifier, args);
        *str += ft_nbr_len(space_nb);
        return (len);
    }
    return (ft_putchar('%'));
}

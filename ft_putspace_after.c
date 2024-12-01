/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:17:54 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:21:03 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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

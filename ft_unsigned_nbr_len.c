/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:18:34 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:22:04 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int ft_unsigned_nbr_len(unsigned int nb)
{
    int len;

    if (nb == 0)
        return (1);
    len = 0;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

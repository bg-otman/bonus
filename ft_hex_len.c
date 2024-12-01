/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:17:23 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:20:29 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int ft_hex_len(unsigned long n)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:17:08 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:20:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int handle_format(const char **str, va_list args)
{
    (*str)++;
    // ft_skip_chars(str, ' ');
    if (is_valid_specifier(**str))
        return (check_specifier(**str, args));
	else if (is_valid_flag(**str))
    	return (handle_flags(str, args));
	else
    {
        if (**str != '\0') 
            return (ft_putchar('%') + ft_putchar(**str));
        return (ft_putchar('%'));
    }
}

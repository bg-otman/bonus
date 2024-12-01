/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:16:56 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:20:08 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int check_signs(const char **str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while ((*str)[i] != '\0' && !is_valid_specifier((*str)[i]))
	{
		if ((*str)[i] == '+')
			n++;
		if ((*str)[i] == '-')
			n++;
		i++;
	}
	return (n);
}

int handle_flags(const char **str, va_list args)
{
	int len;

	len = 0;
	if (**str == ' ' || **str == '+' || check_signs(str) >= 2)
		len = ft_handle_space(str, args);
	else if (**str == '-')
	{
		ft_skip_chars(str, '-');
		if ((**str) >= '1' && (**str) <= '9')
			len = ft_putspace_after(str, args);
		else if (is_valid_specifier(**str))
			len = check_specifier(**str, args);
	}
	else if (**str >= '1' && **str <= '9')
		len = ft_putspace_before(str, args);
	else if (**str == '0')
	{
		len = ft_putzero(str, args);
	}
	else if (**str == '.')
		len = handle_dot(str, args);
	else if (**str == '#')
		len = handle_dash(str, args);
	return (len);
}

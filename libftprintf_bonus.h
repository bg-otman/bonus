/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:01 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/01 14:22:41 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *, ...);
int		check_specifier(char c, va_list args);
int	    ft_putchar(char c);
int	    ft_putnbr(int n);
int	    ft_putstr(char *s);
int     ft_puthex(unsigned int nb, char *hex);
int     ft_putadresse(unsigned long long nb);
int     ft_putunsint(unsigned int nb);
int     is_valid_specifier(char c);
int     ft_putspace_after(const char **str, va_list args);
long	ft_atoi(const char *str);
int     ft_nbr_len(int nb);
void    ft_skip_chars(const char **str, char c);
int     is_valid_flag(char c);
int     get_arg_len(char specifier, va_list args);
int     ft_putspace_before(const char **str, va_list args);
size_t	ft_strlen(const char *s);
int     ft_putzero(const char **str, va_list args);
int     handle_flags(const char **str, va_list args);
int     handle_format(const char **str, va_list args);
int     ft_hex_len(unsigned long n);
int     ft_handle_space(const char **str, va_list args);
int     handle_dot(const char **str, va_list args);
int     ft_unsigned_nbr_len(unsigned int nb);
int     handle_dash(const char **str, va_list args);

#endif

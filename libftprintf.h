/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:01 by obouizi           #+#    #+#             */
/*   Updated: 2024/11/27 11:07:04 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *, ...);
int		check_specifier(char c, va_list args, const char **str);
int     ft_putspace_after(const char **str, va_list args);
int     ft_putbefore(char c, const char **str, va_list args);
int     ft_get_arglen(char c, va_list args);
int	    ft_putchar(char c);
int	    ft_putnbr(int n);
int	    ft_putstr(char *s);
int     ft_count_chars(char c, const char *str);
int     ft_nbr_len(int nb);
int     ft_puthex(unsigned int nb, char *hex);
int     ft_putadresse(unsigned long long nb);
int     ft_putunsint(unsigned int nb);
long	ft_atoi(const char *str);
void    ft_skip_spaces(const char **str);
size_t	ft_strlen(const char *s);
int     is_valid_specifier(char c);

#endif

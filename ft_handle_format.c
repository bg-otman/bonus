#include "libftprintf.h"

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
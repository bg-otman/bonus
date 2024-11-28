#include "libftprintf.h"

int is_valid_specifier(char c)
{
    if ( c == 'c' || c == 's' || c == 'd' || c == 'i'
        || c == 'x' || c == 'X' || c == 'p' || c == 'u')
        return (1);
    return (0);
}
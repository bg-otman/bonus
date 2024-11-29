
#include "libftprintf.h"

int is_valid_flag(char c)
{
    if (c == '-' || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}
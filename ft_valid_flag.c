
#include "libftprintf.h"

int is_valid_flag(char c)
{
    if (c == '-' || (c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '.' || c == '#')
        return (1);
    return (0);
}
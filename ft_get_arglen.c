#include "libftprintf.h"

static int getadresse(unsigned long long nb, char *hex)
{
    int count;
    
    count = 0;
    if (nb >= 16)
        count += getadresse(nb / 16, hex);
    count++;
    return (count);
}

static int     getadresse_len(unsigned long long nb)
{
    int count;
    
    count = 0;
    if (nb == 0)
        count += write(1, "(nil)", 5);
    else
    {
        count += 2;
        count += getadresse(nb, "0123456789abcdef");
    }
    return (count);
}

static int gethex_len(unsigned int nb, char *hex)
{
    int count;
    
    count = 0;
    if (nb >= 16)
        count += gethex_len(nb / 16, hex);
    count++;
    return (count);
}

static int getunsint_len(unsigned int nb)
{
    int count;

	count = 0;
	if (nb >= 10)
		count += getunsint_len(nb / 10);
	count++;
	return (count);
}

int ft_get_arglen(char c, va_list args)
{
    int len;

    len = 0;
    if (c == 's')
		len = ft_strlen(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_nbr_len(va_arg(args, int));
	else if (c == 'c')
		len = 1;
	else if (c == 'x' || c == 'X')
		len = gethex_len(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'u')
		len = getunsint_len((va_arg(args, unsigned int)));
	else if (c == 'p')
		len = getadresse_len((va_arg(args, unsigned long long)));
    return (len);
}

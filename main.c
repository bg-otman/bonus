#include "libftprintf.h"
#include <stdio.h>


int main()
{
    // ft_printf("|hel %-2147483647s|\n", "hi");
    int h = ft_printf("|hel %  -3s|\n", "hi");
    int n = printf("|hel %  -3s|\n", "hi");
    printf("n: %d | h: %d", n, h);
	return 0;
}
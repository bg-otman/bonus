#include "libftprintf.h"
#include <stdio.h>


int main()
{
    
	int n1 = ft_printf("|copy : %-11s|", "ff");
	printf("\n");
	   int n2 = printf("|copy : %-11s|", "ff");
	printf("\n");
	printf("orig : %d | copy : %d\n", n2, n1);
    return 0;
}

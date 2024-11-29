#include "libftprintf.h"
#include <stdio.h>


int main()
{
    
	int n1 = ft_printf("|copy : %        --5s|", "hi");
	printf("\n");
	   int n2 = printf("|orig : %        --5s|", "hi");
	printf("\n");
	printf("orig : %d | copy : %d\n", n2, n1);
    return 0;
}

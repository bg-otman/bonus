#include "libftprintf_bonus.h"


int main()
{
    
	int n1 = ft_printf("|copy : |%#X|", 151);
	printf("\n");
	   int n2 = printf("|orig : |%#X|", 151);
	printf("\n");
	printf("orig : %d | copy : %d\n", n2, n1);
    return 0;
}

/////////////////////////////////

// #include <stdio.h>

// int main() {
//     int n1, n2;

//     // Combination of "+" and "0" flags
//     // n1 = printf("Orig:|%+05d|\n", 10);  // "+" flag with "0" padding
//     // n2 = ft_printf("Cust:|%+05d|\n", 10);
//     // printf("Original: %d | Custom: %d\n", n1, n2);
//     // printf("\n--------------------------\n");

//     return 0;
// }

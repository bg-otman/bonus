#include "libftprintf.h"
#include <stdio.h>


// int main()
// {
    
// 	int n1 = ft_printf("|copy : |%.13X|", 99);
// 	printf("\n");
// 	   int n2 = printf("|orig : |%.13X|", 99);
// 	printf("\n");
// 	printf("orig : %d | copy : %d\n", n2, n1);
//     return 0;
// }

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

#include <stdio.h>

int main() {
    int n1, n2;

    // Tests for `d` and `i` (decimal integers)
    n1 = printf("Orig:|%.5d|\n", 42);
    n2 = ft_printf("Cust:|%.5d|\n", 42);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.0d|\n", 0);  // Precision of zero with zero value
    n2 = ft_printf("Cust:|%.0d|\n", 0);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.3i|\n", -42);  // Negative numbers with precision
    n2 = ft_printf("Cust:|%.3i|\n", -42);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.1d|\n", 123456);  // Precision smaller than number length
    n2 = ft_printf("Cust:|%.1d|\n", 123456);
    printf("Original: %d | Custom: %d\n", n1, n2);

    // Tests for `u` (unsigned integers)
    n1 = printf("Orig:|%.5u|\n", 42);  // Positive unsigned number with precision
    n2 = ft_printf("Cust:|%.5u|\n", 42);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.0u|\n", 0);  // Precision of zero with unsigned zero
    n2 = ft_printf("Cust:|%.0u|\n", 0);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.8u|\n", 4294967295U);  // Max unsigned int with precision
    n2 = ft_printf("Cust:|%.8u|\n", 4294967295U);
    printf("Original: %d | Custom: %d\n", n1, n2);

    // Tests for `x` and `X` (hexadecimal integers)
    n1 = printf("Orig:|%.5x|\n", 42);  // Lowercase hex with precision
    n2 = ft_printf("Cust:|%.5x|\n", 42);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.0x|\n", 0);  // Precision of zero with zero
    n2 = ft_printf("Cust:|%.0x|\n", 0);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.3x|\n", 255);  // Lowercase hex with leading zeroes
    n2 = ft_printf("Cust:|%.3x|\n", 255);
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.6X|\n", 255);  // Uppercase hex with leading zeroes
    n2 = ft_printf("Cust:|%.6X|\n", 255);
    printf("Original: %d | Custom: %d\n", n1, n2);

    // Tests for `s` (strings)
    n1 = printf("Orig:|%.5s|\n", "Hello, world!");  // Truncate to precision
    n2 = ft_printf("Cust:|%.5s|\n", "Hello, world!");
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.0s|\n", "Hello");  // Precision of zero with a string
    n2 = ft_printf("Cust:|%.0s|\n", "Hello");
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.3s|\n", "Hi");  // Precision greater than string length
    n2 = ft_printf("Cust:|%.3s|\n", "Hi");
    printf("Original: %d | Custom: %d\n", n1, n2);

    n1 = printf("Orig:|%.7s|\n", "Short");  // Precision exceeds string length
    n2 = ft_printf("Cust:|%.7s|\n", "Short");
    printf("Original: %d | Custom: %d\n", n1, n2);

    return 0;
}

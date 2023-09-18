#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int Deg_count = 0;
    char c; 
    char buf_of_int[12];
	int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (n < 0)
    {
        write(1, "-", 1);
        Deg_count++;
        n = -n;
    }

    
    while (n > 0) 
    {
        c = (n % 10) + '0';
        buf_of_int[i] = c;
        i++;
        n = n / 10;
    }

    
    for (i = i - 1; i >= 0; i--)
    {
        write(1, &buf_of_int[i], 1);
        Deg_count++;
    }

    return Deg_count;
}


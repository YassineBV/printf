#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_int - function that Print integer.
 * @th_arg: va_list argument.
 * Return: Number of chars printed.
 */
int print_int(va_list th_arg)
{
	int n = va_arg(th_arg, int);
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

	return (Deg_count);
}
/**
 * print_Astr - function that Print string
 * @prtf_ptr: va_list pointer.
 * Return: return the Number of characters printed.
 */
int print_Astr(va_list prtf_ptr)
{
	char *string_out = va_arg(prtf_ptr, char *);
	int len = 0;

	if (string_out == NULL)
		string_out = "(null)";

	while (string_out[len] != '\0')
		len++;
	write(1, string_out, len);
	return (len);
}
/**
 * print_c - Print a character %c
 * @prtf_ptr: The pointer va_list .
 * Return: the Number of characters printed.
 */
int print_c(va_list prtf_ptr)
{
	char one_c = va_arg(prtf_ptr, int);

	write(1, &one_c, 1);
	return (1);
}
/**
 * print_percent - Print a percent character %%
 *  * @prtf_ptr: unused va_list argument.
 * Return: Number of characters printed.
 */
int print_percent(va_list prtf_ptr)
{
	char percent = '%';
	(void)prtf_ptr;

	write(1, &percent, 1);
	return (1);
}

#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int print_Astr(va_list prtf_ptr);
int print_c(va_list prtf_ptr);
int print_percent(void);
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
 * Return: Number of characters printed.
 */
int print_percent(void)
{
	char percent = '%';

	write(1, &percent, 1);
	return (1);
}
/**
 * _printf - local custum printf function.
 * @format: The format string.
 * Return: the Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, char_count = 0;
	va_list prtf_ptr;

	va_start(prtf_ptr, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			switch (format[i])
			{
				case 's':
					char_count += print_Astr(prtf_ptr);
					break;
				case 'c':
					char_count += print_c(prtf_ptr);
					break;
				case '%':
					char_count += print_percent();
					break;

				default:
					return (-1);
			}
		}
		else
		{
			write(1, &format[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(prtf_ptr);
	return (char_count);
}

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * specf_tabl_init - Initialize specifier table
 * @spec_Tab: Pointer to specifier table
 */
void specf_tabl_init(spcf_inf spec_Tab[])
{
	spec_Tab[0].specifier = 's';
	spec_Tab[0].hundl_ptr = print_Astr;

	spec_Tab[1].specifier = 'c';
	spec_Tab[1].hundl_ptr = print_c;

	spec_Tab[2].specifier = '%';
	spec_Tab[2].hundl_ptr = print_percent;

	spec_Tab[3].specifier = 'd';
	spec_Tab[3].hundl_ptr = print_int;

	spec_Tab[4].specifier = 'i';
	spec_Tab[4].hundl_ptr = print_int;


	spec_Tab[5].specifier = '\0';
	spec_Tab[5].hundl_ptr = NULL;
}
/**
 * do_prnt - Performs printing based on format.
 * @format: Format string.
 * @prtf_ptr: va_list pointer.
 * @spc_tab_ar: Specifier table.
 * Return: Number of characters printed.
 */
int do_prnt(const char *format, va_list prtf_ptr, spcf_inf spc_tab_ar[])
{
	int char_count = 0, i, found = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; spc_tab_ar[i].specifier != '\0'; i++)
			{
				if (*format == spc_tab_ar[i].specifier)
				{
					char_count += spc_tab_ar[i].hundl_ptr(prtf_ptr);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				write(1, format - 1, 1);
				write(1, format, 1);
				char_count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}

	return (char_count);
}
/**
 * _printf - Prints formatted data.
 * @format: the Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list prtf_ptr;
	int char_count = 0;
	spcf_inf spc_tab_ar[6];

	specf_tabl_init(spc_tab_ar);

	if (format == NULL || *format == '\0')
		return (-1);
	if (*format == '%' && *(format + 1) == '\0')
		return (-1);
	va_start(prtf_ptr, format);


	char_count = do_prnt(format, prtf_ptr, spc_tab_ar);

	va_end(prtf_ptr);
	return (char_count);
}


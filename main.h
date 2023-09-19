#ifndef MAI_H
#define MAI_H

#include <stdio.h>

/**
 * struct spcf_inf - the Structure that store specifier info.
 * @specifier: The specifier character.
 * @hundl_ptr: Pointer to the handler function.
 */
typedef struct spcf_inf
{
	char specifier;
	int (*hundl_ptr)(va_list);
} spcf_inf;

int print_int(va_list args);
int _printf(const char *format, ...);
int print_Astr(va_list prtf_ptr);
int print_c(va_list prtf_ptr);
int print_percent(va_list prtf_ptr);
int (*get_char(char c))(va_list);
int do_prnt(const char *format, va_list prtf_ptr, spcf_inf spc_tab_ar[]);

/**
 * struct specifier_hundl - Structure to hold specifier and function.
 * @c: The specifier character.
 * @f: Pointer to the function.
 */
typedef struct specifier_hundl
{
	char c;
	int (*f)(va_list);
} specf_t;

#endif

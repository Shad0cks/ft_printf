#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>

int ft_printf(const char *, ...);
int case_printf(const char *format, va_list args);
void ft_putstr(char *str, int *count);
void ft_putchar(int c, int *count);
void ft_putnbr(int nb, int *count);
void hex(int nb, int *count);
int	int_count(unsigned int nb);
void    ft_itoa_unsiged(unsigned int nb, int *count);
void aff_p(uintptr_t p, int *count);



#endif
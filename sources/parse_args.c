#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int case_printf(const char *format, va_list args)
{
    int index;
    int count;

    count = 0;
    index = 0;
    
    while (format[index] != '\0')
    {
        if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'c'))
            ft_putchar(va_arg(args, int), &count);
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 's'))
            ft_putstr(va_arg(args, char *), &count);
        else if (format[index] == '%' && (format[index + 1] && ((format[index + 1] == 'i') || format[index + 1] == 'd')))
            ft_putnbr(va_arg(args, int), &count);
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'p'))
        {
            ft_putstr("0x", &count);
            hex(va_arg(args, unsigned long), "0123456789abcdef", &count);
        }
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'u'))
            ft_itoa_unsiged(va_arg(args, unsigned int), &count); 
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'x' ))
            hex(va_arg(args, unsigned int), "0123456789abcdef", &count);
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'X'))
            hex(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == '%'))
            ft_putchar('%', &count);
        else
        {
            ft_putchar_fd(format[index], 1);
            index++;
            count++;
            continue;
        }
        index += 2;
    }
    return (count);   
}
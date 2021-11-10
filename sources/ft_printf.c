#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int ft_printf(const char *format, ...)
{
    int count;
    va_list args;

    va_start(args, format);
    count = case_printf(format, args);
    va_end(args);

    return (count);
}

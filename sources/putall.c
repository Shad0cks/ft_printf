#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void ft_putnbr(int nb, int *count)
{
    ft_putnbr_fd(nb, 1);
    *count += int_count(nb);
}

void ft_putchar(int c, int *count)
{
    ft_putchar_fd(c, 1);
    *count += 1;
}

void ft_putstr(char *str, int *count)
{
    if (!str)
	{
            ft_putstr_fd("(null)", 1);
            *count += 6;
            return;
    }
    ft_putstr_fd(str, 1);
    *count += ft_strlen(str);
}
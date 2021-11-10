#include "../libft/libft.h"
#include "./ft_printf.h"


void ft_putchar(int c, int *count)
{
    ft_putchar_fd(c, 1);
    *count += 1;
}

void ft_putstr(char *str, int *count)
{
    ft_putstr_fd(str, 1);
    *count += ft_strlen(str);
}

static int	int_count(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count + 1);
}

void ft_putnbr(int nb, int *count)
{
    ft_putnbr_fd(nb, 1);
    *count += int_count(nb);
}

char	*ft_itoa_unsiged(unsigned int nb)
{
	char			*result;
	int				index;

	index = int_count(nb);
	result = malloc(sizeof(char) * int_count(nb) + 1);
	if (result == NULL)
		return (NULL);
	result[index] = '\0';
	while (nb / 10)
	{
		result[index - 1] = (nb % 10) + '0';
		index--;
		nb /= 10;
	}
	result[index - 1] = (nb % 10) + '0';
	return (result);
}


void aff_u(unsigned int nb, int *count)
{
    ft_putstr(ft_itoa_unsiged(nb), count);
}

void aff_p(uintptr_t p, int *count)
{
    char buf[sizeof(p) * 2];
    size_t i;

    i = 0;
    while (i < sizeof(p) * 2)
    {
        buf[i] = "0123456789ABCDEF"[(p >> ((sizeof(p) * 2 - 1 - i) * 4)) & 0xf];
        i++;
    }
    *count += sizeof(buf);
    write(1, buf, sizeof(buf));
}

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	a--;
	while (a >= i)
	{
		tmp = str[i];
		str[i] = str[a];
		str[a] = tmp;
		i++;
		a--;
	}
	return (str);
}


void hex(int nb, int *count)
{   
    int index = 0;
    char str[20];
    while (nb >= 16)
    {
        str[index] = "0123456789abcdef"[nb % 16];
        nb /= 16;
        index++;
    }
    str[index] = "0123456789abcdef"[nb];
    str[index + 1] = '\0';
    
    ft_putstr(ft_strrev(str), count);
}



int case_printf(char *format, va_list args)
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
            aff_p(va_arg(args, uintptr_t), &count);
        else if (format[index] == '%' && (format[index + 1] && format[index + 1] == 'u'))
            aff_u(va_arg(args, unsigned int), &count); 
        else if (format[index] == '%' && (format[index + 1] && ((format[index + 1] == 'x') || format[index + 1] == 'X')))
            hex(va_arg(args, int), &count);
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

int ft_printf(char *format, ...)
{
    int count;
    va_list args;

    va_start(args, format);
    count = case_printf(format, args);
    va_end(args);

    return (count);
}

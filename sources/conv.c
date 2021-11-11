#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static char	*ft_strrev(char *str)
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

void hex(unsigned long nb, char* base ,int *count)
{   
    int index = 0;
    char str[20];
    while (nb >= 16)
    {
        str[index] = base[nb % 16];
        nb /= 16;
        index++;
    }
    str[index] = base[nb];
    str[index + 1] = '\0';
    ft_putstr(ft_strrev(str), count);
}

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

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

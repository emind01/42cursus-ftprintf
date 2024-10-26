#include "ft_printf.h"

void    ft_putchar_len(char c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}

void    ft_putstr(char *s, int *len)
{
    size_t  i;

    i = 0;
    if (!s)
    {
        write(1, "(null)", 6);
        (*len) += 6;
        return ;
    }
    while (s[i])
    {
        ft_putchar_len(s[i], len);
        i++;
    }
}

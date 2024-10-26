#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void    ft_putchar_len(char c, int *len);
void    ft_putstr(char *s, int *len);
void    ft_putnbr(int num, int *len);
void    ft_putunbr(unsigned int num, int *len);
void    ft_puthex(unsigned int num, int *len, char c);
void    ft_putptr(size_t ptr, int *len);
int     ft_printf(const char *str, ...);

#endif
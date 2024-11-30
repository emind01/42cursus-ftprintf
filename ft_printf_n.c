/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muduran <muduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:12:00 by muduran           #+#    #+#             */
/*   Updated: 2024/10/29 18:12:00 by muduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr(num * -1, len);
	}
	else
	{
		if (num > 9)
			ft_putnbr(num / 10, len);
		ft_putchar_len(num % 10 + '0', len);
	}
}

void	ft_putunbr(unsigned int num, int *len)
{
	if (num >= 10)
		ft_putunbr(num / 10, len);
	ft_putchar_len(num % 10 + '0', len);
}

void	ft_puthex(unsigned int num, int *len, char c)
{
	char	s[8];
	char	*base;
	int		i;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (num == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (num != 0)
	{
		s[i] = base [num % 16];
		num = num / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(s[i], len);
}

void	ft_putptr(size_t ptr, int *len)
{
	char	s[18];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	while (ptr)
	{
		s[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_len(s[i], len);
		i--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:49:14 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/30 00:50:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_hexa(unsigned int nbr, int *count, int *flags)
{
	if (nbr >= 16)
	{
		ft_putnbr_hexa(nbr / 16, count, flags);
		ft_putnbr_hexa(nbr % 16, count, flags);
	}
	else
	{
		if (flags[_TYP_VAR] == _NBR_HEX_MIN)
			ft_putchar_fd(BASE16_MIN[nbr], _STD_OUT, count);
		else if (flags[_TYP_VAR] == _NBR_HEX_MAX)
			ft_putchar_fd(BASE16_MAJ[nbr], _STD_OUT, count);
	}
}

void	ft_putnbr_ptr(unsigned long long nbr, int fd, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_ptr(nbr / 16, fd, count);
		ft_putnbr_ptr(nbr % 16, fd, count);
	}
	else
		ft_putchar_fd(BASE16_MIN[nbr], fd, count);
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", _STD_OUT, count);
		*count += 11;
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putnbr_fd(n / 10, fd, count);
		ft_putnbr_fd(n % 10, fd, count);
	}
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd, count);
	else
		ft_putstr_fd("(null)", fd, count);
}

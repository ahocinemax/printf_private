/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:49:14 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/30 00:50:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(long long nbr, char c, int fd, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_hexa(nbr / 16, c, fd, count);
		ft_putnbr_hexa(nbr % 16, c, fd, count);
	}
	else
	{
		if (c == 'x')
			ft_putchar_fd(BASE16_MIN[nbr], fd, count);
		if (c == 'X')
			ft_putchar_fd(BASE16_MAJ[nbr], fd, count);
	}
}

void	ft_putnbr_ptr(long long nbr, int fd, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_ptr(nbr / 16, fd, count);
		ft_putnbr_ptr(nbr % 16, fd, count);
	}
	else
		ft_putchar_fd(BASE16_MIN[nbr], fd, count);
}

void	ft_putlong_fd(long n, int fd, int *count)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putnbr_fd(n / 10, fd, count);
		ft_putnbr_fd(n % 10, fd, count);
	}
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putnbr_fd(n / 10, fd, count);
		ft_putnbr_fd(n % 10, fd, count);
	}
}

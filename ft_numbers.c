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

void	ft_putnbr_hexa(long long nbr, char c, int *count, int *flags)
{
	if (nbr >= 16)
	{
		ft_putnbr_hexa(nbr / 16, c, count, flags);
		ft_putnbr_hexa(nbr % 16, c, count, flags);
	}
	else
	{
		if (c == 'x')
			ft_putchar_fd(BASE16_MIN[nbr], _STD_OUT, count, flags);
		if (c == 'X')
			ft_putchar_fd(BASE16_MAJ[nbr], _STD_OUT, count, flags);
	}
}

void	ft_putnbr_ptr(long long nbr, int fd, int *count, int *flags)
{
	if (nbr >= 16)
	{
		ft_putnbr_ptr(nbr / 16, fd, count, flags);
		ft_putnbr_ptr(nbr % 16, fd, count, flags);
	}
	else
		ft_putchar_fd(BASE16_MIN[nbr], fd, count, flags);
}

void	ft_putlong_fd(long n, int fd, int *count, int *flags)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count, flags);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count, flags);
	else
	{
		ft_putnbr_fd(n / 10, fd, count, flags);
		ft_putnbr_fd(n % 10, fd, count, flags);
	}
}

void	ft_putnbr_fd(int n, int fd, int *count, int *flags)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", _STD_OUT, count, flags);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count, flags);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count, flags);
	else
	{
		ft_putnbr_fd(n / 10, fd, count, flags);
		ft_putnbr_fd(n % 10, fd, count, flags);
	}
}

void	ft_display_num(int typ_param, va_list lst_param, int *count, int *flags)
{
	long long	ptr;

	if (typ_param == _INT)
		ft_int(va_arg(lst_param, int), flags, count);
	else if (typ_param == _LONG)
		ft_long(va_arg(lst_param, long), flags, count);
	else if (typ_param == _NBR_HEX_MIN || typ_param == _NBR_HEX_MAX)
		ft_hexa(typ_param, va_arg(lst_param, long), flags, count);
	else if (typ_param == _PTR_HEX)
	{
		ptr = va_arg(lst_param, long);
		ft_putstr_fd("0x", _STD_OUT, count, flags);
		if (ptr == -1)
			ft_putstr_fd("ffffffffffffffff", _STD_OUT, count, flags);
		else
			ft_putnbr_ptr(ptr, _STD_OUT, count, flags);
	}
}

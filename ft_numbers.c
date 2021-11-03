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

void	ft_putnbr_ptr(unsigned long nbr, int fd, int *count)
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
		n *= -1;
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putlong_fd(n / 10, fd, count);
		ft_putlong_fd(n % 10, fd, count);
	}
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

int	ft_display_num(va_list lst_param, int *count, int *flags)
{
	unsigned long	ptr;

	if (flags[_TYP_VAR] == _INT)
		ft_int(va_arg(lst_param, int), flags, count);
	else if (flags[_TYP_VAR] == _LONG)
		ft_long(va_arg(lst_param, long), flags, count);
	else if (flags[_TYP_VAR] == _NBR_HEX_MIN || flags[_TYP_VAR] == _NBR_HEX_MAX)
		ft_hexa(va_arg(lst_param, unsigned int), flags, count);
	else if (flags[_TYP_VAR] == _PTR_HEX)
	{
		ptr = va_arg(lst_param, long);
		ft_count_hexa(ptr, flags);
		flags[_LEN_VAR] += 2;
		ft_putspace(flags, count, flags[_LEN_VAR]);
		ft_putstr_fd("0x", _STD_OUT, count);
		if (ptr == (unsigned long)UINT_MIN)
		{
			flags[_LEN_VAR] = 18;
			ft_putstr_fd("ffffffffffffffff", _STD_OUT, count);
		}
		else
			ft_putnbr_ptr(ptr, _STD_OUT, count);
	}
	else
		return (0);
	return (1);
}

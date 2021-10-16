/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:29:33 by ahocine           #+#    #+#             */
/*   Updated: 2021/09/27 17:29:37 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hexa(long long nbr)
{
	long long	remainder;
	char		hexa[14];
	int			i;

	i = 0;
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexa[i++] = BASE16_MIN[remainder];
		nbr = nbr / 16;
	}
	hexa[i] = 0;
	return (ft_strlen(hexa));
}

void	ft_flags_b1(char **str, int *flags)
{
	if (**str == '#')
	{
		flags[_HASH]++;
		(*str)++;
	}
	else if (**str == ' ')
	{
		flags[_SPACE]++;
		while (**str == ' ')
			(*str)++;
	}
	else if (**str == '+')
	{
		flags[_PLUS]++;
		while (**str == '+')
			(*str)++;
	}
}

void	ft_int(int res, int *flags, int *count)
{
	char	*len;

	len = ft_itoa(res);
	if (res >= 0 && flags[_PLUS] > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (res >= 0 && flags[_SPACE] > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	if (res < 0)
	{
		res = -res;
		ft_putchar_fd('-', _STD_OUT, count);
	}
	if (flags[_WIDTH_Z]> 0 && flags[_ZERO])
	{
		flags[_WIDTH_Z] -= ft_strlen(len);
		ft_putflag(flags, count);
	}
	ft_putlong_fd(res, _STD_OUT, count);
	if (flags[_WIDTH_Z]> 0 && flags[_MINUS])
	{
		flags[_WIDTH_Z] -= ft_strlen(len);
		ft_putflag(flags, count);
	}
	free(len);
}

void	ft_long(long ptr, int *flags, int *count)
{
	char	*len;

	len = ft_itoa(ptr);
	if (flags[_PLUS] > 1 && ptr > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (flags[_SPACE] && ptr > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	else if (ptr < 0)
		ft_putchar_fd('-', _STD_OUT, count);
	flags[_WIDTH_Z] -= ft_strlen(len);
	if (flags[_WIDTH_Z] - 1 > 0 && flags[_ZERO])
		ft_putflag(flags, count);
	ft_putlong_fd(ptr, _STD_OUT, count);
	if (flags[_WIDTH_M] - 1 > 0 && flags[_MINUS])
		ft_putflag(flags, count);
	free(len);
}

void	ft_hexa(int typ_param, long ptr, int *flags, int *count)
{
	int	len;

	if (ptr == 4294967295)
		len = 8;
	else
		len = ft_count_hexa(ptr);
	if (flags[_WIDTH_Z] > 1)
	{
		flags[_WIDTH_Z] -= len;
		ft_putflag(flags, count);
	}
	if (typ_param == _NBR_HEX_MIN)
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0x", _STD_OUT, count);
		ft_putnbr_hexa(ptr, 'x', count);
	}
	else
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0X", _STD_OUT, count);
		ft_putnbr_hexa(ptr, 'X', count);
	}
}

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
		ft_putchar_fd('+', _STD_OUT, count, flags);
	else if (res >= 0 && flags[_SPACE] > 0)
		ft_putchar_fd(' ', _STD_OUT, count, flags);
	if (flags[_WIDTH_Z] - 1 > 0 && flags[_ZERO])
	{
		flags[_WIDTH_Z] -= ft_strlen(len);
		ft_putflag(flags, count);
	}
	ft_putlong_fd(res, _STD_OUT, count, flags);
	if (flags[_WIDTH_Z] - 1 > 0 && flags[_MINUS])
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
		ft_putchar_fd('+', _STD_OUT, count, flags);
	else if (flags[_SPACE] && ptr > 0)
		ft_putchar_fd(' ', _STD_OUT, count, flags);
	flags[_WIDTH_Z] -= ft_strlen(len);
	if (flags[_WIDTH_Z] - 1 > 0 && flags[_ZERO])
		ft_putflag(flags, count);
	ft_putlong_fd(ptr, _STD_OUT, count, flags);
	if (flags[_WIDTH_M] - 1 > 0 && flags[_MINUS])
		ft_putflag(flags, count);
	free(len);
}

void	ft_hexa(int typ_param, long ptr, int *flags, int *count)
{
	char	*len;

	len = ft_itoa(ptr);
	if (flags[_WIDTH_Z] - 1 > 0)
	{
		flags[_WIDTH_Z] -= ft_strlen(len);
		ft_putflag(flags, count);
	}
	if (typ_param == _NBR_HEX_MIN)
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0x", _STD_OUT, count, flags);
		ft_putnbr_hexa(ptr, 'x', count, flags);
	}
	else
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0X", _STD_OUT, count, flags);
		ft_putnbr_hexa(ptr, 'X', count, flags);
	}
	free(len);
}

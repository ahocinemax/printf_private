/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:29:33 by ahocine           #+#    #+#             */
/*   Updated: 2021/09/27 17:29:37 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(int res, int *flags, int *count)
{
	if (res >= 0 && flags[_PLUS] > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (res >= 0 && flags[_SPACE] > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	ft_putnbr_fd(res, _STD_OUT, count);
}

void	ft_long(long ptr, int *flags, int *count)
{
	if (flags[_PLUS] > 1 && ptr > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (flags[_SPACE] && ptr > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	ft_putlong_fd(ptr, _STD_OUT, count);
}

void	ft_hexa(int typ_param, long ptr, int *flags, int *count)
{
	if (typ_param == _NBR_HEX_MIN)
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0x", _STD_OUT, count);
		ft_putnbr_hexa(ptr, 'x', _STD_OUT, count);
	}
	else
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0X", _STD_OUT, count);
		ft_putnbr_hexa(ptr, 'X', _STD_OUT, count);
	}
}

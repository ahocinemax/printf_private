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

void	ft_count_hexa(long nbr, int *flags)
{
	if (nbr >= 16)
	{
		ft_count_hexa(nbr / 16, flags);
		ft_count_hexa(nbr % 16, flags);
	}
	else
		flags[_LEN_VAR]++;
}

static void	ft_sign(int *res, int *flags, int *count, int *neg)
{
	if (*res >= 0 && flags[_PLUS])
		ft_putchar_fd('+', _STD_OUT, count);
	else if (*res >= 0 && flags[_SPACE] == 1)
		ft_putchar_fd(' ', _STD_OUT, count);
	else if (*res < 0)
	{
		*res *= -1;
		*neg = -1;
		ft_putchar_fd('-', _STD_OUT, count);
		if ((flags[_SPACE] == 1 || flags[_ZERO] > 1) && *neg < 0)
			flags[_LEN_VAR]--;
	}
}

void	ft_int(int res, int *flags, int *count)
{
	int	neg;

	flags[_LEN_VAR] = ft_counter(res, flags);
	if (flags[_SPACE] != 2 && flags[_ZERO] == 3 && flags[7] != -1 && res < 0)
		flags[_WIDTH_S]--;
	ft_putspace(flags, count, flags[_LEN_VAR]);
	ft_sign(&res, flags, count, &neg);
	ft_putzero(flags, count, flags[_LEN_VAR]);
	if (flags[_ZERO] != 2 && flags[_ZERO] && !flags[_WIDTH_Z] && !res)
	{
		flags[_LEN_VAR] = 0;
		return ;
	}
	else
		ft_putlong_fd(res, _STD_OUT, count);
	if (flags[_ZERO] == 3 && neg == -1)
		flags[_LEN_VAR]++;
}

void	ft_long(long ptr, int *flags, int *count)
{
	flags[_LEN_VAR] = ft_counter(ptr, flags);
	ft_putspace(flags, count, flags[_LEN_VAR]);
	if (flags[_PLUS] > 1 && ptr >= 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (flags[_SPACE] == 1 && ptr > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	else if (ptr < 0)
		ft_putchar_fd('-', _STD_OUT, count);
	ft_putzero(flags, count, flags[_LEN_VAR]);
	if (flags[_ZERO] && flags[_ZERO] != 2 && !flags[_WIDTH_Z] && !ptr)
	{
		flags[_LEN_VAR] = 0;
		return ;
	}
	else
		ft_putlong_fd(ptr, _STD_OUT, count);
}

void	ft_hexa(unsigned int ptr, int *flags, int *count)
{
	if (ptr == 4294967295)
		flags[_LEN_VAR] = 8;
	else if (!ptr && flags[_POINT] && !flags[_WIDTH_Z])
		flags[_LEN_VAR] = 0;
	else
		ft_count_hexa((long)ptr, flags);
	ft_putspace(flags, count, flags[_LEN_VAR]);
	if (flags[_TYP_VAR] == _NBR_HEX_MIN && flags[_HASH] && ptr)
		ft_putstr_fd("0x", _STD_OUT, count);
	else if (flags[_TYP_VAR] == _NBR_HEX_MAX && flags[_HASH] && ptr)
		ft_putstr_fd("0X", _STD_OUT, count);
	ft_putzero(flags, count, flags[_LEN_VAR]);
	if (flags[_ZERO] != 2 && flags[_ZERO] && !flags[_WIDTH_Z] && !ptr)
	{
		flags[_LEN_VAR] = 0;
		return ;
	}
	else
		ft_putnbr_hexa(ptr, count, flags);
}

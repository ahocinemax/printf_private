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

static void	ft_count_hexa(long long nbr, int *flags)
{
	if (nbr >= 16)
	{
		ft_count_hexa(nbr / 16, flags);
		ft_count_hexa(nbr % 16, flags);
	}
	else
		flags[_LEN_VAR]++;
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
	char	*tmp;

	tmp = ft_itoa(res);
	flags[_LEN_VAR] = ft_strlen(tmp);
	free(tmp);
	if (res >= 0 && flags[_PLUS] > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (res >= 0 && flags[_SPACE] > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	if (res < 0)
	{
		res = -res;
		ft_putchar_fd('-', _STD_OUT, count);
	}
	if (flags[_WIDTH_Z] > 0 && flags[_ZERO])
	{
		flags[_WIDTH_Z] -= flags[_LEN_VAR];
		ft_putflag(flags, count, flags[_LEN_VAR]);
	}
	ft_putlong_fd(res, _STD_OUT, count);
	if (flags[_WIDTH_Z] > 0 && flags[_MINUS])
	{
		flags[_WIDTH_Z] -= flags[_LEN_VAR];
		ft_putflag(flags, count, flags[_LEN_VAR]);
	}
}

void	ft_long(long ptr, int *flags, int *count)
{
	char	*tmp;

	tmp = ft_itoa(ptr);
	flags[_LEN_VAR] = ft_strlen(tmp);
	free(tmp);
	if (flags[_PLUS] > 1 && ptr > 0)
		ft_putchar_fd('+', _STD_OUT, count);
	else if (flags[_SPACE] && ptr > 0)
		ft_putchar_fd(' ', _STD_OUT, count);
	else if (ptr < 0)
		ft_putchar_fd('-', _STD_OUT, count);
	flags[_WIDTH_Z] -= flags[_LEN_VAR];
	if (flags[_WIDTH_Z] - 1 > 0 && flags[_ZERO])
		ft_putflag(flags, count, flags[_LEN_VAR]);
	ft_putlong_fd(ptr, _STD_OUT, count);
	if (flags[_WIDTH_M] - 1 > 0 && flags[_MINUS])
		ft_putflag(flags, count, flags[_LEN_VAR]);
}

void	ft_hexa(long ptr, int *flags, int *count)
{
	if (ptr == 4294967295)
		flags[_LEN_VAR] = 8;
	else
		ft_count_hexa(ptr, flags);
	if (flags[_WIDTH_Z] > 1)
		ft_putflag(flags, count, flags[_LEN_VAR]);
	if (flags[_POINT] == 1 && flags[_WIDTH_P] == 0)
		return ;
	if (flags[_TYP_VAR] == _NBR_HEX_MIN)
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0x", _STD_OUT, count);
		ft_putnbr_hexa(ptr, count, flags);
	}
	else
	{
		if (flags[_HASH] && ptr)
			ft_putstr_fd("0X", _STD_OUT, count);
		ft_putnbr_hexa(ptr, count, flags);
	}
}

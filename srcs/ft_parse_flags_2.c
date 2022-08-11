/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:56:16 by ahocine           #+#    #+#             */
/*   Updated: 2021/09/16 18:56:21 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putzero(int *flags, int *count, int len)
{
	if ((flags[_ZERO] == 1 || flags[_ZERO] == 3) && flags[_WIDTH_Z] > 0)
	{
		flags[_WIDTH_Z] -= len;
		while (flags[_WIDTH_Z]-- > 0)
		{
			flags[_LEN_VAR]++;
			ft_putchar_fd('0', _STD_OUT, count);
		}
	}
}

void	ft_putspace(int *flags, int *count, int len)
{
	if (flags[_ZERO] == 2 && !flags[_SPACE] && flags[_WIDTH_Z] > 0)
	{
		if (flags[_WIDTH_P] > len)
			flags[_WIDTH_Z] -= flags[_WIDTH_S];
		else
			flags[_WIDTH_Z] -= len;
		while (flags[_WIDTH_Z]-- > 0)
			ft_putchar_fd(' ', _STD_OUT, count);
	}
	else if (flags[_SPACE] == 2 && flags[_WIDTH_S] > 0)
	{
		if (flags[_WIDTH_Z] >= len)
		{
			if (flags[_ZERO])
				flags[_WIDTH_S] -= flags[_WIDTH_Z] + (flags[_NEG]);
			flags[_WIDTH_S] -= flags[_WIDTH_P];
		}
		else
			flags[_WIDTH_S] -= len;
		while (flags[_WIDTH_S]-- > 0)
			ft_putchar_fd(' ', _STD_OUT, count);
	}
}

void	ft_minus(int *flags, char **s)
{
	flags[_MINUS] = 1;
	(*s)++;
	flags[_WIDTH_M] = ft_atoi(*s);
	while (**s && **s >= '0' && **s <= '9')
		(*s)++;
}

void	ft_zero(int *flags, char **s)
{
	if (**s == '0')
		flags[_ZERO] = 1;
	else
		flags[_ZERO] = 2;
	flags[_WIDTH_Z] = ft_atoi(*s);
	while (**s && **s >= '0' && **s <= '9')
		(*s)++;
}

void	ft_sign(int *res, int *flags, int *count)
{
	if (*res >= 0 && flags[_PLUS])
		ft_putchar_fd('+', _STD_OUT, count);
	else if (*res >= 0 && flags[_SPACE] == 1)
		ft_putchar_fd(' ', _STD_OUT, count);
	else if (flags[_NEG])
	{
		*res *= -1;
		ft_putchar_fd('-', _STD_OUT, count);
		if ((flags[_SPACE] == 1 || flags[_ZERO] > 1))
			flags[_LEN_VAR]--;
	}
}

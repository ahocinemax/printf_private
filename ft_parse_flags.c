/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:26 by ahocine           #+#    #+#             */
/*   Updated: 2021/11/02 22:28:28 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(int *f)
{
	if (f[5] && !f[3] && f[10] != 1 && f[10] != 2 && f[10] != 5)
	{
		f[_WIDTH_Z] = f[_WIDTH_P];
		f[_POINT] = 0;
		f[_ZERO] = 3;
	}
	else if (f[5] && f[3] && f[10] != 1 && f[10] != 2 && f[10] != 5)
	{
		if (!f[_WIDTH_P])
		{
			f[_WIDTH_S] = f[_WIDTH_Z];
			f[_WIDTH_Z] = 0;
		}
		else if (f[_WIDTH_Z] >= f[_WIDTH_P])
		{
			f[_WIDTH_S] = f[_WIDTH_Z];
			f[_WIDTH_Z] = f[_WIDTH_P];
		}
		else if (f[_WIDTH_Z] < f[_WIDTH_P])
			f[_WIDTH_Z] = f[_WIDTH_P];
		f[_WIDTH_P] = 0;
		f[_SPACE] = 2;
		f[_ZERO] = 3;
	}
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

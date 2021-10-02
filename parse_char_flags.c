/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:13:07 by ahocine           #+#    #+#             */
/*   Updated: 2021/10/02 20:13:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_b2(char **str, int *flags)
{
	if (**str == '.')
	{
		flags[_POINT]++;
		(*str)++;
	}
	else if (**str == '-')
	{
		flags[_MINUS]++;
		while (**str == ' ')
			(*str)++;
	}
	else if (**str == '0')
	{
		flags[_ZERO]++;
		while (**str == '+')
			(*str)++;
	}
}

void	ft_display_text(int type, va_list lst_param, int *count, int *flags)
{
	char	*str;

	if (type == _CHAR)
		ft_putchar_fd((char)va_arg(lst_param, int), _STD_OUT, count);
	else if (type == _STRING)
	{
		str = va_arg(lst_param, char *);
		if (str)
			ft_putstr_fd(str, _STD_OUT, count);
		else
			ft_putstr_fd("(null)", _STD_OUT, count);
	}
}

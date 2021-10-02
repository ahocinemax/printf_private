/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:13:07 by ahocine           #+#    #+#             */
/*   Updated: 2021/10/02 20:13:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_b2(char **str, int *flags)
{
	int	width;

	width = 0;
	if (**str == '.')
	{
		flags[_POINT]++;
		(*str)++;
	}
	else if (**str == '-')
	{
		flags[_MINUS]++;
		(*str)++;
		while (**str >= 0 && **str < 10)
		{
			width += (**str) - '0';
			(*str)++;
		}
	}
	else if (**str == '0')
	{
		flags[_ZERO]++;
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

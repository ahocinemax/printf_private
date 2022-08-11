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

#include "../includes/ft_printf.h"

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

void	ft_flags_b2(char **s, int *flags)
{
	while (**s && (**s == '-' || (**s >= '0' && **s <= '9') || **s == '.'))
	{
		if (**s == '-')
			ft_minus(flags, s);
		if (**s >= '0' && **s <= '9')
			ft_zero(flags, s);
		if (**s == '.')
		{
			flags[_POINT] = 1;
			(*s)++;
			if (**s && **s >= '0' && **s <= '9')
				flags[_WIDTH_P] = ft_atoi(*s);
			else
				flags[_WIDTH_P] = 0;
			while (**s && **s >= '0' && **s <= '9')
				(*s)++;
		}
	}
}

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

void	ft_display_text(va_list lst_param, int *count, int *flags)
{
	char	*str;

	if (flags[_TYP_VAR] == _CHAR)
	{
		ft_putspace(flags, count, 1);
		if (flags[_POINT] > 0 && flags[_WIDTH_P] < 1)
			return ;
		ft_putchar_fd((char)va_arg(lst_param, int), _STD_OUT, count);
	}
	else if (flags[_TYP_VAR] == _STRING)
	{
		str = va_arg(lst_param, char *);
		if (!str)
			str = "(null)";
		flags[_LEN_VAR] = ft_strlen(str);
		ft_putspace(flags, count, flags[_LEN_VAR]);
		if (flags[_POINT] && flags[_WIDTH_P] < flags[_LEN_VAR])
		{
			flags[_LEN_VAR] = flags[_WIDTH_P];
			while (flags[_WIDTH_P]-- > 0)
				ft_putchar_fd(*(str++), _STD_OUT, count);
		}
		else
			ft_putstr_fd(str, _STD_OUT, count);
	}
}

int	ft_display_num(va_list lst_param, int *count, int *flags)
{
	long	ptr;

	if (flags[_TYP_VAR] == _INT)
		ft_int(va_arg(lst_param, int), flags, count);
	else if (flags[_TYP_VAR] == _LONG)
		ft_long(va_arg(lst_param, unsigned int), flags, count);
	else if (flags[_TYP_VAR] == _NBR_HEX_MIN || flags[_TYP_VAR] == _NBR_HEX_MAX)
		ft_hexa(va_arg(lst_param, unsigned int), flags, count);
	else if (flags[_TYP_VAR] == _PTR_HEX)
	{
		ptr = va_arg(lst_param, long);
		ft_pointer(ptr, flags, count);
	}
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:39:19 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/26 21:39:24 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_count_flags(const char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			res++;
		i++;
	}
	return (res);
}

static int	ft_conversion(char **str, int *flags)
{
	int	res;

	if (**str == 'd' || **str == 'i')
		res = _INT;
	else if (**str == 'u')
		res = _LONG;
	else if (**str == 'c')
	{
		res = _CHAR;
		flags[_LEN_VAR] = 1;
	}
	else if (**str == 's')
		res = _STRING;
	else if (**str == 'x')
		res = _NBR_HEX_MIN;
	else if (**str == 'X')
		res = _NBR_HEX_MAX;
	else if (**str == 'p')
		res = _PTR_HEX;
	else
		return (-1);
	(*str)++;
	return (res);
}

static void	ft_write_line(char **line, va_list lst_param, int *count)
{
	char	*split;
	int		flags[12];

	ft_init_flags(flags);
	split = *line;
	if (*split == '%')
	{
		split++;
		ft_flags_b1(&split, flags);
		ft_flags_b2(&split, flags);
		flags[_TYP_VAR] = ft_conversion(&split, flags);
		ft_parse_flags(flags);
		ft_display_num(lst_param, count, flags);
		ft_display_text(lst_param, count, flags);
		while (flags[_MINUS] && flags[_WIDTH_M]-- > flags[_LEN_VAR])
			ft_putchar_fd(' ', _STD_OUT, count);
	}
	ft_putstr_fd(split, _STD_OUT, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_param;
	char	**s;
	int		nbr_param;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(lst_param, str);
	s = ft_split_printf(str, '%');
	nbr_param = ft_count_flags(str) + 1;
	while (s[i] && i < nbr_param)
	{
		if (ft_count_flags(s[i]) == ft_strlen(s[i]) || !ft_count_flags(s[i]))
			ft_putstr_fd(s[i], _STD_OUT, &count);
		else
			ft_write_line(&s[i], lst_param, &count);
		free(s[i++]);
	}
	free(s);
	va_end(lst_param);
	return (count);
}

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

static int	ft_conversion(char **str)
{
	int	res;

	if (**str == 'd' || **str == 'i')
		res = _INT;
	else if (**str == 'u')
		res = _LONG;
	else if (**str == 'c')
		res = _CHAR;
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

static void	ft_num_flags(char **str, int *flags)
{
	if (**str == '#')
	{
		flags[_HASH]++;
		(*str)++;
	}
	if (**str == ' ')
	{
		flags[_SPACE]++;
		while (**str == ' ')
			(*str)++;
	}
	if (**str == '+')
	{
		flags[_PLUS]++;
		while (**str == '+')
			(*str)++;
	}
}

static void	ft_write_line(char **line, va_list lst_param, int *count)
{
	int		typ_param;
	char	*split;
	int		flags[3];
	int		flags2[3];

	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags2[0] = 0;
	flags2[1] = 0;
	flags2[2] = 0;
	split = *line;
	if (*split == '%')
	{
		split++;
		ft_num_flags(&split, flags);
		ft_char_flags(&split, flags2);
		typ_param = ft_conversion(&split);
		ft_display_num(typ_param, lst_param, count, flags);
		ft_display_text(typ_param, lst_param, count, flags2);
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

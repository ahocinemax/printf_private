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

int	ft_count_flags(const char *str)
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

int	ft_flags(char **str)
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

void	ft_write_line(char **line, va_list lst_param, int *count)
{
	int		typ_param;
	long	ptr;
	char	*split;
	char	*str;

	split = *line;
	split++;
	typ_param = ft_flags(&split);
	if (typ_param == _CHAR)
		ft_putchar_fd((char)va_arg(lst_param, int), _STD_OUT, count);
	else if (typ_param == _INT)
		ft_putnbr_fd(va_arg(lst_param, int), _STD_OUT, count);
	else if (typ_param == _LONG)
		ft_putlong_fd(va_arg(lst_param, long), _STD_OUT, count);
	else if (typ_param == _STRING)
	{
		str = va_arg(lst_param, char *);
		if (str)
			ft_putstr_fd(str, _STD_OUT, count);
		else
			ft_putstr_fd("(null)", _STD_OUT, count);
	}
	else if (typ_param == _NBR_HEX_MIN)
		ft_putnbr_hexa(va_arg(lst_param, long), 'x', _STD_OUT, count);
	else if (typ_param == _NBR_HEX_MAX)
		ft_putnbr_hexa(va_arg(lst_param, long), 'X', _STD_OUT, count);
	else if (typ_param == _PTR_HEX)
	{
		ptr = va_arg(lst_param, long);
		ft_putstr_fd("0x", _STD_OUT, count);
		if (ptr == -1)
			ft_putstr_fd("ffffffffffffffff", _STD_OUT, count);
		else
			ft_putnbr_ptr(ptr, _STD_OUT, count);
	}
	ft_putstr_fd(split, _STD_OUT, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_param;
	char	**split;
	int		nbr_param;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(lst_param, str);
	split = ft_split_printf(str, '%');
	nbr_param = ft_count_flags(str) + 1;
	while (split[i] && i < nbr_param)
	{
		if (ft_count_flags(split[i]) == ft_strlen(split[i]) || !ft_count_flags(split[i]))
			ft_putstr_fd(split[i], _STD_OUT, &count);
		else
			ft_write_line(&split[i], lst_param, &count);
		free(split[i++]);
	}
	free(split);
	va_end(lst_param);
	return (count);
}

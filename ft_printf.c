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

int	ft_count_args(const char *str)
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

int	ft_type(char **str)
{
	int	res;

	if (**str == 'd' || **str == 'i' || **str == 'u')
		res = _INT;
	else if (**str == 'c')
		res = _CHAR;
	else if (**str == 's')
		res = _STRING;
	else if (**str == 'p' || **str == 'x')
		res = _PTR_HEX;
	else
		res = -1;
	if (res != -1)
		(*str)++;
	return (res);
}

void	ft_write_line(char *split, va_list lst_param)
{
	int	typ_param;
	int	i;

	i = 0;
	typ_param = ft_type(&split);
	if (typ_param == _CHAR)
	{
		ft_putchar_fd(va_arg(lst_param, int), 1);
	}
	else if (typ_param == _INT)
	{
		ft_putnbr_fd(va_arg(lst_param, int), 1);
	}
	else if (typ_param == _STRING)
	{
		ft_putstr_fd(va_arg(lst_param, char *), 1);
	}
	else if (typ_param == _PTR_HEX)
	{
		ft_putnbr_fd(va_arg(lst_param, int), 1);
	}
	ft_putstr_fd(split, 1);
	i++;
}

int	ft_printf(const char *str, ...)
{
	char	**split;
	int		i;
	int		nbr_param;
	va_list	lst_param;

	va_start(lst_param, str);
	i = 0;
	split = ft_split(str, '%');
	nbr_param = ft_count_args(str) + 1;
	while (split[i] && i < nbr_param)
	{
		ft_write_line(split[i], lst_param);
		free(split[i]);
		i++;
	}
	free(split);
	va_end(lst_param);
	return (0);
}

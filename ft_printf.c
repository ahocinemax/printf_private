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

int	ft_type(char *str)
{
	int	res;

	if (*str == 'd' || *str == 'i' || *str == 'u')
		res = _INT;
	else if (*str == 'c')
		res = _CHAR;
	else if (*str == 's')
		res = _STRING;
	else if (*str == 'p' || *str == 'x')
		res = _PTR_HEX;
	else
		res = -1;
	if (res != -1)
		str++;
	return (res);
}

/*void	ft_write_line(char *str, int format, ...)
{
	if (format == _INT)
		ft_putnbr_fd(format, 1);
}*/

int ft_printf(const char *str, ...)
{
	char	**split;
	int		i;
	int		nbr_param;
	va_list	lst_param;

	va_start(lst_param, str);
	i = 0;
	split = ft_split(str, '%');
	nbr_param = ft_type(split[i]);
	while (split[i])
	{
		printf("i = %d -> [%s]\n", nbr_param, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	va_end(lst_param);
	return (0);
}

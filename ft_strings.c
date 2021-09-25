/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:56:16 by ahocine           #+#    #+#             */
/*   Updated: 2021/09/16 18:56:21 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd, count);
	else
		ft_putstr_fd("(null)", fd, count);
}

void	ft_display_text(int typ_param, va_list lst_param, int *count)
{
	char	*str;

	if (typ_param == _CHAR)
		ft_putchar_fd((char)va_arg(lst_param, int), _STD_OUT, count);
	else if (typ_param == _STRING)
	{
		str = va_arg(lst_param, char *);
		if (str)
			ft_putstr_fd(str, _STD_OUT, count);
		else
			ft_putstr_fd("(null)", _STD_OUT, count);
	}
}

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

void	ft_putchar_fd(char c, int fd, int *count, int *flags)
{
	if (flags)
	{
		if (*count > flags[_WIDTH_P] && flags[_POINT])
		{
			return ;
		}
	}
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putstr_fd(char *s, int fd, int *count, int *flags)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd, count, flags);
	else
		ft_putstr_fd("(null)", fd, count, flags);
}

void	ft_init_flags(int *flags)
{
	flags[_WIDTH_P] = 0;
	flags[_WIDTH_Z] = 0;
	flags[_WIDTH_M] = 0;
	flags[_SPACE] = 0;
	flags[_POINT] = 0;
	flags[_MINUS] = 0;
	flags[_PLUS] = 0;
	flags[_HASH] = 0;
	flags[_ZERO] = 0;
}

int	ft_atoi(char *nb)
{
	long	i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			neg = -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return ((int)res * (int)neg);
}

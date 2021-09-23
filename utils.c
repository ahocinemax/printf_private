/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd, count);
	if (n < 0)
		n *= -1;
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putnbr_fd(n / 10, fd, count);
		ft_putnbr_fd(n % 10, fd, count);
	}
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd, count);
	else
		ft_putstr_fd("(null)", fd, count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:49:14 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/30 00:50:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putllong_fd(unsigned long long nbr, int fd, int *count)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd, count);
	else
	{
		ft_putlong_fd(nbr / 10, fd, count);
		ft_putlong_fd(nbr % 10, fd, count);
	}
}

void	ft_putlong_fd(long n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
	else
	{
		ft_putlong_fd(n / 10, fd, count);
		ft_putlong_fd(n % 10, fd, count);
	}
}

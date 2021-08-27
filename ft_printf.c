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
#include "libft/libft.h"

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

void	ft_write_line(char *str, int format, ...)
{
	if (format == _INT)
		ft_putnbr_fd(str, 1);
}

int main(void)
{
	char	*str = "line %d : [%s]\n";
	char	**split;
	int		i = 0;

	split = ft_split(str, '%');

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:13:07 by ahocine           #+#    #+#             */
/*   Updated: 2021/10/02 20:13:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(int *flags, int *count, int len)
{
	if (flags[_ZERO] == 2 && flags[_WIDTH_Z] > 0)
	{
		flags[_WIDTH_Z] -= len;
		while (flags[_WIDTH_Z]-- > 0 && flags[_LEN_VAR]++)
			ft_putchar_fd(' ', _STD_OUT, count);
	}
}

void	ft_flags_b2(char **str, int *flags)
{
	while (**str && (**str == '-' || (**str >= '0' && **str <= '9') || **str == '.'))
	{
		if (**str == '-')
		{
			flags[_MINUS] = 1;
			(*str)++;
			flags[_WIDTH_M] = ft_atoi(*str);
			while (**str && **str >= '0' && **str <= '9')
				(*str)++;
		}
		if (**str >= '0' && **str <= '9')
		{
			if (**str == '0')
				flags[_ZERO] = 1;
			else
				flags[_ZERO] = 2;
			flags[_WIDTH_Z] = ft_atoi(*str);
			while (**str && **str >= '0' && **str <= '9')
				(*str)++;
		}
		if (**str == '.')
		{
			flags[_POINT] = 1;
			(*str)++;
			if (**str && **str >= '0' && **str <= '9')
				flags[_WIDTH_P] = ft_atoi(*str);
			else
				flags[_WIDTH_P] = 0;
			while (**str && **str >= '0' && **str <= '9')
				(*str)++;
		}
	}
}

void	ft_display_text(va_list lst_param, int *count, int *flags)
{
	char	*str;
	char	letter;

	if (flags[_TYP_VAR] == _CHAR)
	{
		letter = (char)va_arg(lst_param, int);
		flags[_LEN_VAR] = 1;
		ft_putspace(flags, count, 1);
		if (flags[_POINT] > 0 && flags[_WIDTH_P] < 1)
			return ;
		ft_putchar_fd(letter, _STD_OUT, count);
	}
	else if (flags[_TYP_VAR] == _STRING)
	{
		str = va_arg(lst_param, char *);
		if (!str)
			str = "(null)";
		flags[_LEN_VAR] = ft_strlen(str);
		ft_putspace(flags, count, flags[_LEN_VAR]);
		if (flags[_POINT] && flags[_WIDTH_P] < flags[_LEN_VAR])
		{
			flags[_LEN_VAR] = flags[_WIDTH_P];
			while (flags[_WIDTH_P]-- > 0)
				ft_putchar_fd(*(str++), _STD_OUT, count);
		}
		else
			ft_putstr_fd(str, _STD_OUT, count);
	}
}

int	ft_counter(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	char	*res;
	size_t	index;
	long	nbr;

	index = ft_counter(n);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	res = malloc(sizeof(char) * (index + 1));
	if (!res)
		return (NULL);
	res[index--] = 0;
	while (index > 0)
	{
		res[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	else
		res[0] = nbr + '0';
	return (res);
}

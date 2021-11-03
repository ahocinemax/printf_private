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
	if (flags[_ZERO] == 2 && !flags[_SPACE] && flags[_WIDTH_Z] > 0)
	{
		if (flags[_WIDTH_P] > len)
			flags[_WIDTH_Z] -= flags[_WIDTH_S];
		else
			flags[_WIDTH_Z] -= len;
		while (flags[_WIDTH_Z]-- > 0)
			ft_putchar_fd(' ', _STD_OUT, count);
	}
	else if (flags[_SPACE] == 2 && flags[_WIDTH_S] > 0)
	{
		if (flags[_WIDTH_Z] >= len)
		{
			if (flags[_ZERO])
				flags[_WIDTH_S] -= flags[_WIDTH_Z] + (flags[_NEG]);
			flags[_WIDTH_S] -= flags[_WIDTH_P];
		}
		else
			flags[_WIDTH_S] -= len;
		while (flags[_WIDTH_S]-- > 0)
			ft_putchar_fd(' ', _STD_OUT, count);
	}
}

void	ft_flags_b2(char **s, int *flags)
{
	while (**s && (**s == '-' || (**s >= '0' && **s <= '9') || **s == '.'))
	{
		if (**s == '-')
			ft_minus(flags, s);
		if (**s >= '0' && **s <= '9')
			ft_zero(flags, s);
		if (**s == '.')
		{
			flags[_POINT] = 1;
			(*s)++;
			if (**s && **s >= '0' && **s <= '9')
				flags[_WIDTH_P] = ft_atoi(*s);
			else
				flags[_WIDTH_P] = 0;
			while (**s && **s >= '0' && **s <= '9')
				(*s)++;
		}
	}
}

void	ft_display_text(va_list lst_param, int *count, int *flags)
{
	char	*str;

	if (flags[_TYP_VAR] == _CHAR)
	{
		ft_putspace(flags, count, 1);
		if (flags[_POINT] > 0 && flags[_WIDTH_P] < 1)
			return ;
		ft_putchar_fd((char)va_arg(lst_param, int), _STD_OUT, count);
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

int	ft_counter(long n, int *flags)
{
	int	len;

	if (!n && flags[_POINT] && !flags[_WIDTH_Z])
		return (0);
	len = 1;
	if (n < 0)
	{
		len++;
		flags[_NEG] = 1;
	}
	while (n < -9 || n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long n, int *flags)
{
	char	*res;
	size_t	index;
	long	nbr;

	index = ft_counter(n, flags);
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

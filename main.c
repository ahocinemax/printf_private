/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:39:07 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/27 10:39:09 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*line = "bonsoir";
	int		i = 4;
	char	**ptr = &line;

	ft_printf("line%%95 %d : \"%s\" %p", i, line, ptr);
	ft_putchar_fd('\n', _STD_OUT);
	printf("line%%95 %d : \"%s\" %p\n", i, line, ptr);
	return (0);
}

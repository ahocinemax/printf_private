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
	char	**res;
	int		i;
	int		ret1;
	int		ret2;

	i = 0;
	write(1, "[ %p %p ]", 10);
	printf("*************** SPLIT RESULT ***************\n");
	res = ft_split_printf(" %p %p ", '%');
	while (res[i])
	{
		printf("\'%s\'\n", res[i]);
		free(res[i++]);
	}
	free(res);
	printf("\n*************** PRINTF RESULT ***************\n");
	write(1, "GOT      : ", 12);
	ret1 = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	write(1, "\n", 2);
	write(1, "EXPECTED : ", 12);
	ret2 = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\nMy return       : %d\n", ret1);
	printf("Expected return : %d\n", ret2);
	return (0);
}

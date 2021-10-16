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

	i = 0;
	write(1, "[%012d]\n", 9);
	printf("*************** SPLIT RESULT ***************\n");
	res = ft_split_printf("%012d\n", '%');
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	printf("\n*************** PRINTF RESULT ***************\n");
	write(1, "GOT      : ", 12);
	ft_printf("%012d", (int)-2147483648);
	write(1, "\n", 2);
	write(1, "EXPECTED : ", 12);
	printf("%012d", (int)-2147483648);
	return (0);
}

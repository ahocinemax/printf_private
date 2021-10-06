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
	write(1, "[%01.2x]\n", 10);
	printf("*************** SPLIT RESULT ***************\n");
	res = ft_split_printf("%01.2x\n", '%');
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	printf("\n*************** PRINTF RESULT ***************\n");
	ft_printf("%01.2x\n", 4);
	write(1, "\n", 2);
	printf("%1.2x\n", 	4);
	return (0);
}

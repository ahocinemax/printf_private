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
	write(1, "%+d\n", 4);
	printf("*************** SPLIT RESULT ***************\n");
	res = ft_split_printf("%+d\n", '%');
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	printf("\n*************** PRINTF RESULT ***************\n");
	ft_printf("%+d\n", 0);
	write(1, "\n", 2);
	printf("%+d\n", 0);
	return (0);
}

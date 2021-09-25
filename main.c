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
	write(1, "%%c%%s%%p\n", 11);
	printf("*************** SPLIT RESULT ***************\n");
	res = ft_split_printf("%%c%%s%%p\n", '%');
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	printf("\n*************** PRINTF RESULT ***************\n");
	ft_printf("%%c%%s%%p\n");
	write(1, "\n", 2);
	printf("%%c%%s%%p\n");
	return (0);
}

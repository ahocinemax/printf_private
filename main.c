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
	res = ft_split_printf("[Got] : %%\n", '%');
	while (res[i])
	{
		ft_printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	//printf("[Got] : %%\n");
	//printf("[Expected] : %%\n");
	return (0);
}

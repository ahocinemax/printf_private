/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:39:32 by ahocine           #+#    #+#             */
/*   Updated: 2021/08/26 21:39:44 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define _INT		0
# define _CHAR		1
# define _STRING	2
# define _PTR_HEX	3

# include "../libft_private/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

void	ft_write_line(char *split, va_list lst_param);
int		ft_printf(const char *str, ...);
int		ft_count_args(const char *str);
int		ft_type(char **str);

#endif	

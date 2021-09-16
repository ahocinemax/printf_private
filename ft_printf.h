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

# define _INT			0
# define _CHAR			1
# define _STRING		2
# define _NBR_HEX_MIN	3
# define _NBR_HEX_MAX	4
# define _PTR_HEX		5
# define _STD_OUT		1
# define BASE16_MIN		"0123456789abcdef"
# define BASE16_MAJ 	"0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split_printf(const char *str, char sep);
void	ft_write_line(char *split, va_list lst_param);
void	ft_putnbr_hexa(long long nbr, char c, int fd);
void	ft_putnbr_ptr(long long nbr, int fd);
int		ft_printf(const char *str, ...);
int		ft_count_flags(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(const char *str);
int		ft_flags(char **str);

#endif	

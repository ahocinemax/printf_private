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
# define _LONG			6
# define _STD_OUT		1
# define _SPACE			0
# define _HASH			1
# define _PLUS			2
# define _ZERO			3
# define _MINUS			4
# define _POINT			5
# define _WIDTH_Z		6
# define _WIDTH_P		7
# define _WIDTH_M		8
# define _LEN_VAR		9
# define _TYP_VAR		10

# define BASE16_MIN		"0123456789abcdef"
# define BASE16_MAJ 	"0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

// Main functions

int		ft_printf(const char *str, ...);
char	**ft_split_printf(const char *str, char sep);
void	ft_flags_b1(char **str, int *flags);
void	ft_flags_b2(char **str, int *flags);
void	ft_display_num(va_list param, int *c, int *flags);
void	ft_display_text(va_list param, int *c, int *flags);

// Utils

void	ft_hexa(long ptr, int *flags, int *count);
void	ft_long(long ptr, int *flags, int *count);
void	ft_int(int res, int *flags, int *count);
int		ft_strlen(const char *str);
void	ft_init_flags(int *flags);
char	*ft_itoa(long nb);
int		ft_atoi(char *str);

// Diplay functions

void	ft_putnbr_hexa(long long nbr, int *count, int *flags);
void	ft_putflag(int *flags, int *count, int len);
void	ft_putnbr_ptr(long long nbr, int fd, int *count);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putlong_fd(long n, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);

#endif

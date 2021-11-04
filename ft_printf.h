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

/* TYPE_OF_VARIABLE*/
# define _INT			0
# define _CHAR			1
# define _STRING		2
# define _NBR_HEX_MIN	3
# define _NBR_HEX_MAX	4
# define _PTR_HEX		5
# define _LONG			6
# define _STD_OUT		1

/* MANAGED_FLAGS */
# define _SPACE			0
# define _HASH			1
# define _PLUS			2
# define _ZERO			3
# define _MINUS			4
# define _POINT			5

/* SIZE_FLAGS */
# define _WIDTH_Z		6
# define _WIDTH_P		7
# define _WIDTH_M		8
# define _LEN_VAR		9
# define _TYP_VAR		10
# define _WIDTH_S		11
# define _NEG			12

# define BASE16_MIN		"0123456789abcdef"
# define BASE16_MAJ 	"0123456789ABCDEF"

# define UINT_MIN		-2147483648
# define UINT_MAX		2147483647
# define LONG_MIN		-4294967296
# define LONG_MAX		4294967295
# define LLONG_MIN		-9223372036854775808
# define LLONG_MAX		9223372036854775807

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
void	ft_parse_flags(int *flags);
int		ft_display_num(va_list param, int *c, int *flags);
void	ft_display_text(va_list param, int *c, int *flags);

// Utils

void	ft_hexa(unsigned int ptr, int *flags, int *count);
void	ft_pointer(long ptr, int *flags, int *count);
void	ft_sign(int *res, int *flags, int *count);
void	ft_long(long ptr, int *flags, int *count);
void	ft_int(int res, int *flags, int *count);
void	ft_count_hexa(long nbr, int *flags);
int		ft_counter(long n, int *flags);
void	ft_minus(int *flags, char **s);
void	ft_zero(int *flags, char **s);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
char	*ft_itoa(long nb, int *flags);

// Diplay functions

void	ft_putllong_fd(unsigned long long nbr, int fd, int *count);
void	ft_putnbr_hexa(unsigned int nbr, int *count, int *flags);
void	ft_putnbr_ptr(long nbr, int fd, int *count);
void	ft_putspace(int *flags, int *count, int len);
void	ft_putzero(int *flags, int *count, int len);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putlong_fd(long n, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);

#endif

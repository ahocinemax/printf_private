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
# define BASE16_MIN		"0123456789abcdef"
# define BASE16_MAJ 	"0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

// Ordre d'apparition

int		ft_printf(const char *str, ...);
char	**ft_split_printf(const char *str, char sep);
void	ft_flags_b1(char **str, int *flags);
void	ft_flags_b2(char **str, int *flags);
void	ft_display_num(int typ_param, va_list param, int *c, int *flags);
void	ft_display_text(int typ_param, va_list param, int *c, int *flags2);

// Utils

char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	ft_int(int res, int *flags, int *count);
void	ft_long(long ptr, int *flags, int *count);
void	ft_hexa(int typ_param, long ptr, int *flags, int *count);

// Diplay functions

void	ft_putnbr_hexa(long long nbr, char c, int fd, int *count);
void	ft_putnbr_ptr(long long nbr, int fd, int *count);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putlong_fd(long n, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);

#endif

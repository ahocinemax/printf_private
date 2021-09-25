/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:08:08 by ahocine           #+#    #+#             */
/*   Updated: 2021/09/22 17:29:46 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cntline(const char *str, char sep)
{
	int	i;
	int	count_sep;

	i = 0;
	if (!str)
		return (0);
	count_sep = 1;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
		{
			count_sep++;
			i++;
			if (str[i] && str[i] == sep)
				i++;
		}
		while (str[i] && str[i] != sep)
		{
			if (i > 0 && str[i - 1] != sep)
				count_sep++;
			i++;
		}
	}
	return (count_sep);
}

static int	ft_malloc_arr(char ***arr, const char **str, char *sep)
{
	int	len;

	len = ft_cntline(*str, *sep);
	if (len > 0)
		*arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!*arr)
		return (1);
	return (0);
}

static char	*ft_malloc_sep(int *size_line, char **line, char sep)
{
	char	*dest;
	int		len;

	len = 0;
	*size_line = 0;
	if (!(*line))
		return (NULL);
	while ((*line)[len] && (*line)[len] == sep)
		len++;
	dest = (char *)malloc(sizeof(char) * ((len) + 1));
	if (!dest)
		return (NULL);
	while ((*line)[*size_line] && *size_line < len)
	{
		dest[*size_line] = (*line)[*size_line];
		(*size_line)++;
	}
	dest[*size_line / 2] = 0;
	return (dest);
}

static char	*ft_malloc_line(int *size_line, char **line, char sep)
{
	char	*dest;
	int		len;

	len = 0;
	*size_line = 0;
	if (!(*line))
		return (NULL);
	while (((*line))[len] && ((*line))[len] != sep)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while ((*line)[*size_line] && *size_line < len)
	{
		dest[*size_line] = (*line)[*size_line];
		(*size_line)++;
	}
	dest[*size_line] = 0;
	return (dest);
}

char	**ft_split_printf(const char *ptr, char sep)
{
	char	**arr;
	int		index;
	int		s_line;
	char	*str;

	str = (char *)ptr;
	index = 0;
	if (ft_malloc_arr(&arr, &ptr, &sep))
		return (NULL);
	while (index < ft_cntline(ptr, sep) && ft_strlen(str) && *str)
	{
		if (*str && *str != sep)
		{
			arr[index++] = ft_malloc_line(&s_line, &str, sep);
			str += s_line;
		}
		while (*str && *str == sep)
		{
			arr[index] = ft_malloc_sep(&s_line, &str, sep);
			if (*arr[index])
			{
				str += s_line;
				index++;
			}
			else
			{
				free(arr[index]);
				str++;
			}
		}
	}
	arr[index] = 0;
	return (arr);
}

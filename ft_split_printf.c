/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:08:08 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/22 17:29:46 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_private/libft.h"

static int	ft_cntline(const char *str, char sep, int *s_line)
{
	int	i;
	int	count_sep;

	*s_line = 0;
	i = 0;
	count_sep = 1;
	if (*str != '%')
		count_sep++;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
		{
			count_sep++;
			i++;
			if (str[i] && str[i] == sep)
				i++;
			if (str[i] && str[i] != sep)
			{
				count_sep++;
				i++;
			}
		}
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count_sep);
}

static int	ft_init(int *a, int *b)
{
	*a = 0;
	*b = 0;
	return (1);
}

static int	ft_malloc_arr(char ***arr, const char **str, char *sep)
{
	int	len;
	int	err;

	len = ft_cntline(*str, *sep, &err);
	if (len > 0)
		*arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!*arr)
		return (0);
	return (1);
}

static char	*ft_malloc_word(int size_line, const char *word_to_malloc)
{
	char	*dest;
	int		i;

	i = 0;
	if (!word_to_malloc)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (size_line + 1));
	if (!dest)
		return (NULL);
	while (word_to_malloc[i] && i < size_line)
	{
		dest[i] = word_to_malloc[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split_printf(const char *str, char sep)
{
	char	**arr;
	int		index;
	int		i;
	int		s_line;

	if (ft_init(&index, &i) && !ft_malloc_arr(&arr, &str, &sep))
		return (NULL);
	while (index < ft_cntline(str, sep, &s_line) && i < (int)strlen(str))
	{
		while ((char)str[s_line + i] && ((char)str[s_line + i] != sep))
			s_line++;
		if (s_line > 0)
		{
			arr[index++] = ft_malloc_word(s_line, (char *)&str[i]);
			i += s_line;
		}
		if ((char)str[i + 1] && (char)str[i + 1] == sep && (char)str[i] == sep)
			arr[index++] = ft_malloc_word(1, (char *)&str[i++]);
		i++;
	}
	if (str[i] && index < ft_cntline(str, sep, &s_line))
		arr[index++] = ft_malloc_word((int)strlen(str) - i, (char *)&str[i]);
	arr[index] = 0;
	return (arr);
}

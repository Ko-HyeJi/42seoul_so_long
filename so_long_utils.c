/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:59 by hyko              #+#    #+#             */
/*   Updated: 2022/06/11 22:11:39 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static char	**ft_malloc_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	i = 0;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		total_word;
	int		next_word_len;
	int		i;

	if (s == NULL)
		return (NULL);
	total_word = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (total_word + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < total_word)
	{
		while (*s == c)
			s++;
		next_word_len = word_len(s, c);
		str[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (str[i] == NULL)
			return (ft_malloc_error(str));
		ft_strlcpy(str[i], s, next_word_len + 1);
		s += next_word_len;
	}
	str[i] = NULL;
	return (str);
}
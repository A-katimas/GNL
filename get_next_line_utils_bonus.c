/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:03:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/12/02 17:15:12 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;
	int		i;

	cast_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cast_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cast_c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc( size_t nmemb, size_t size )
{
	size_t	i;
	size_t	j;
	void	*tab;
	char	*la;

	j = 0;
	i = nmemb * size ;
	if (size && (i / size != nmemb))
		return (NULL);
	tab = malloc(i);
	if (!tab)
		return (NULL);
	else
	{
		la = tab;
		while (j < i)
		{
			la[j] = '\0';
			j++;
		}
	}
	return (tab);
}

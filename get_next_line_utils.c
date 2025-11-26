/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:11:58 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/26 15:39:16 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	tab = ft_calloc(i, sizeof(char));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, i);
	ft_strlcat(tab, s2, i);
	return (tab);
}
void	*ft_calloc( size_t nmemb, size_t size )
{
	size_t	i ;
	void	*tab;

	i = nmemb * size ;
	if (size && (i / size != nmemb))
		return (NULL);
	tab = malloc(i);
	if (!tab)
		return (NULL);
	else
		ft_memset(tab, '\0', i);
	return (tab);
}

size_t	ft_strlcat( char *dst, const char *src, size_t size)
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
size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	i;
	char	*src1;

	i = 0;
	src1 = (char *)src;
	if (!dst && !src)
		return (dst[i]);
	while (src1[i])
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src1[i] && (i < size - 1))
	{
		dst[i] = src1[i];
		i++;
	}
	dst[i] = '\0';
	while (src1[i])
		i++;
	return (i);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*la;

	la = s;
	i = 0;
	while (i < n)
	{
		la[i] = c;
		i++;
	}
	return (s);
}
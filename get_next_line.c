/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/26 15:25:59 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc( size_t nmemb, size_t size );
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);
size_t	ft_strlcat( char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);

char *get_next_line(int fd)
{
	size_t		strlen = 0;
	static char str[BUFFER_SIZE];
	// char		*tampon ;
	ssize_t		miss ;
	int j = 0;
	int i = 0;
	// printf("\tla str(%s)\n",str);
	while (str[i]!='\0'&& str[i]!='\n' && i!=BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
		i = 0;
	if (!str[i])
	{
		miss = read(fd, str,BUFFER_SIZE );
		if (miss < BUFFER_SIZE)
			return NULL;
	}
	i--;
	while (str[++i]&&str[i] != '\n')
	{

		if (i == BUFFER_SIZE-1)
		{
			i = -1;
			miss = read(fd, str,BUFFER_SIZE );
			if (miss < BUFFER_SIZE)
				return NULL;
			// printf(" |%s| ", str);
		}
		strlen++;
		j++;

	}
	printf("%d",i);
	char *str_return = ft_calloc(sizeof(char *), j+1);

	str_return = ft_strjoin(str_return, str);


	// printf("\treturn -%s-\n", str_return);
	// printf("\tfin du masacre \n");
	return(str_return);
}

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
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

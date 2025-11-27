/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/27 19:45:29 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_get_line(char *str);

char *get_next_line(int fd)
{
	size_t		strlen = 0;
	static char str[1024][BUFFER_SIZE];
	char		*tampon ;
	ssize_t		miss ;
	int j = 0;
	int i = 0;
	tampon = str[fd];
	tampon = ft_calloc(sizeof (char *),1);
	while (str[fd][j]!='\0'&& str[fd][j]!='\n' && j!=BUFFER_SIZE)
		j++;
	if (!str[fd][j-1])
	{
		miss = read(fd, str[fd],BUFFER_SIZE );
		j = miss;
		if (miss == 0)
			return NULL;
	}
	i--;
	while (str[fd][++i]&&str[fd][i] != '\n')
	{
		if (i == j-1)
		{
			i = -1;
			tampon = ft_strfree1join(tampon, str[fd]);
			miss = read(fd, str[fd],BUFFER_SIZE );
			if (miss < 0)
				return 0;
			j = miss ;
		}
		strlen++;
	}
	tampon = ft_strfree1join(tampon, str[fd]);
	printf("%zu",strlen);
	char *str_return = ft_calloc(sizeof(char *), strlen+2);
	str_return = ft_get_line (tampon);
	ft_strlcpy(str[fd],&str[fd][strlen+1], BUFFER_SIZE-strlen);

	return(str_return);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_get_line(char *str)
{
	char	*str_return;
	int		i;

	i = 0;
	if (!str)
		return (str);
	while (str[i] && str[i] != '\n')
		i++;
	str_return = malloc((sizeof(char) * i) + 2);
	if (!str_return)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str_return[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}
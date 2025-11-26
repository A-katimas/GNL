/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/26 23:43:00 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s);

char *get_next_line(int fd)
{
	size_t		strlen = 0;
	static char str[1024][BUFFER_SIZE];
	char		*tampon ;
	ssize_t		miss ;
	int j = 0;
	int i = 0;
	tampon = "";
	while (str[fd][i]!='\0'&& str[fd][i]!='\n' && i!=BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
		i = 0;
	if (!str[fd][i])
	{
		miss = read(fd, str[fd],BUFFER_SIZE );
		if (miss < BUFFER_SIZE)
			return NULL;
	}
	if (i == 0)
		i--;
	while (str[fd][++i]&&str[fd][i] != '\n')
	{
		if (i == BUFFER_SIZE-1)
		{
			i = -1;
			tampon = ft_strjoin(tampon, str[fd]);
			miss = read(fd, str[fd],BUFFER_SIZE );
			if (miss < BUFFER_SIZE)
				return NULL;
		}
		strlen++;
		j++;

	}
	tampon = ft_strjoin(tampon, str[fd]);
	printf("%d",i);
	char *str_return = ft_calloc(sizeof(char *), j+1);

	str_return = ft_strjoin(str_return, tampon);

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

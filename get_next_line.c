/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/30 00:13:01 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_get_line(char *str);
char	*needline(char *str_base, int fd);

char *get_next_line(int fd)
{
	static char str[1024][BUFFER_SIZE];
	char		*tampon ;
	ssize_t		miss ;

	tampon = str[fd];
	tampon = ft_calloc(sizeof (char *),1);
	if (!str[fd][0])
	{
		miss = read(fd, str[fd],BUFFER_SIZE );
			if (miss == 0)
			return NULL;
	}

	tampon = needline(str[fd],fd);

	char *str_return;
	str_return = ft_get_line (tampon);

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

char	*needline(char *str_base, int fd)
{
	//char * buffer[BUFFER_SIZE];
	char	*str_return;
	ssize_t	miss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_return = ft_calloc(BUFFER_SIZE+1,sizeof(char *));
	str_return = ft_strfree1join(str_return,str_base);

	while (str_return[j] && str_return[j] != '\n')
	{
		j++;
	}

	if (j < BUFFER_SIZE)
		ft_strlcpy(str_return,&str_return[j+1],BUFFER_SIZE);
	while (str_base[i] && str_base[i] != '\n')
	{
		if (i == j-1 || i == BUFFER_SIZE-1)
		{
			i = -1;
			miss = read(fd, str_base, BUFFER_SIZE );
			str_return = ft_strfree1join(str_return, str_base);
			if (miss == 0)
				return 0;
			j = miss ;
		}
		i++;
	}

	return (str_return);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/26 15:39:23 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

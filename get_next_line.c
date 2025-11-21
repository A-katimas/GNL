/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:13:45 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/21 15:14:35 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
	size_t	strlen = 0;
	static char str[BUFFER_SIZE];
	ssize_t miss = read(fd ,str,BUFFER_SIZE );
	if (miss < BUFFER_SIZE)
		return NULL;
	printf("%s\n",str);
	int j = 0;
	int i = 0;
	int k = 0;

	while (str[strlen]&&str[strlen] != '\n')
	{
		strlen++;
		j++;
	}
	char *strreturn = malloc(j+1 * sizeof(char *));

	while (str[strlen+1]&&str[strlen+1] != '\n')
	{
		str[k] = str[strlen];
		k++;
}
	while(j)
	{
		strreturn[i] = str[i];
		j-- ;
		i++;
	}
	strlen++;
	return(strreturn);
}


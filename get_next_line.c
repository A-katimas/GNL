/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:02:23 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/12/02 17:17:25 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str_base[1024][BUFFER_SIZE + 1];
	char		*str;
	char		*tampon;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tampon = ft_need_line(fd, str_base[fd]);
	str = ft_the_line(tampon);
	if (!str)
	{
		free(tampon);
		return (NULL);
	}
	tampon = ft_get_new_line(tampon);
	if (!tampon)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str_base[fd], tampon, ft_strlen(tampon) + 1);
	free(tampon);
	return (str);
}

char	*ft_need_line(int fd, char *str_base_need)
{
	int		miss;
	char	*str;

	miss = 1;
	if (str_base_need)
		str = ft_calloc(ft_strlen(str_base_need) + 1, sizeof(char));
	else
		str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, str_base_need, ft_strlen(str_base_need) + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(str, '\n') && miss != 0)
	{
		miss = read(fd, str_base_need, BUFFER_SIZE);
		if (miss == -1)
			return (free(str), NULL);
		str_base_need[miss] = '\0';
		str = ft_strjoin(str, str_base_need);
		if (!str || ft_strlen(str) == 0)
			return (free(str), NULL);
	}
	return (str);
}

char	*ft_get_new_line(char	*str)
{
	char	*str_return;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str_return = ft_calloc(((ft_strlen(str) - i) + 1), sizeof(char));
	if (!str_return)
		return (NULL);
	j = 0;
	while (str[i])
		str_return[j++] = str[i++];
	free(str);
	return (str_return);
}

char	*ft_the_line(char *str)
{
	char	*str_return;
	int		i;

	i = 0;
	if (!str)
		return (str);
	while (str[i] && str[i] != '\n')
		i++;
	str_return = ft_calloc(i + 2, sizeof(char));
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
	return (str_return);
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

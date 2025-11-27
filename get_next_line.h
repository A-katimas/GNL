/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:14:22 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/27 19:43:48 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char 	*get_next_line(int fd);
char	*ft_strfree1join(void *s1, char const *s2);
void	*ft_calloc( size_t nmemb, size_t size );
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);
size_t	ft_strlcat( char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);

#endif
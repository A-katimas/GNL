/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:27:50 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/21 15:15:07 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int main() {
    char *buffer;
    int fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s",buffer);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		printf("%s",buffer);
	}
	free(buffer);
    close(fd);
    return 0;
}

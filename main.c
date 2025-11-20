/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:27:50 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/20 14:32:21 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void chat(unsigned int i , char* miou);

int main() {
    char buffer[BUFFER_SIZE];
    int fd = open("test.txt", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
	printf("%sla",buffer);
    close(fd);
    return 0;
}

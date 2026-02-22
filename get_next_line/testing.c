/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:50:34 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/21 21:50:36 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
    int   fd;
    char *line;
	int i = 0;
    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);
	while(i != 50) {
    line = get_next_line(fd);
	printf("%s",line);
    free(line);
		i++;
	}
    close(fd);
    return (0);
}

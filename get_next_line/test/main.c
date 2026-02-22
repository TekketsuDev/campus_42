/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:58:48 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/21 22:04:40 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void	test_text(char *filename)
{
	int	fd;
	char	*line;
	int	i;

	i = 1;
	printf("===== TESTING: %s ======\n", filename);
	
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		printf("Error opening file\n");
		return ;
	}

	while((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", i++, line);
		free(line);
	}
	
	close(fd);
}



int main(void)
{
	test_text("test/test1.txt");
	test_text("test/test2.txt");
	test_text("test/test3.txt");
	test_text("test/test5.txt");
	
	test_text("test/test4.txt");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:10:39 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/18 18:38:36 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		file;
	char	buff;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file < 0)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		while (read(file, &buff, 1))
			write(1, &buff, 1);
		close(file);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:14:58 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/12 17:27:29 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	length;

	length = 0;
	while (s1[length] != '\0' && s2[length] != '\0')
	{
		if (s1[length] != s2[length])
			return (s1[length] - s2[length]);
		length++;
	}
	return (s1[length] - s2[length]);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	display(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i++ < argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (argc -1))
	{
		j = 1;
		while (j < (argc -1))
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap_str(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}
	display(argc, argv);
	return (0);
}

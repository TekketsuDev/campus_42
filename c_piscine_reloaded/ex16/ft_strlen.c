/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:18:47 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/17 12:28:02 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}
/*
int	main(void)
{
	char	*b;
	b = "Hola tengo hambre";
	ft_strlen(b);
	printf("%d", ft_strlen(b));
	return (0);
}
*/

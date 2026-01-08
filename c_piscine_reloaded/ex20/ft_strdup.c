/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:40:57 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/12 19:55:56 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*src_cpy;

	i = 0;
	if (!src)
		return (NULL);
	src_cpy = (char *)malloc(ft_strlen(src) + 1);
	if (!src_cpy)
		return (NULL);
	while (src[i])
	{
		src_cpy[i] = src[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}

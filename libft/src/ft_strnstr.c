/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:38:52 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:38:52 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	if (!need || *need == '\0')
		return ((char *)hay);
	if (!hay || len == 0)
		return (NULL);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (need[j] && i + j < len && hay[i + j] == need[j])
			j++;
		if (need[j] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}

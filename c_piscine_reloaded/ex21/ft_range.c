/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:27:59 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/12/16 19:38:03 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*num_matrix;
	int	i;

	i = 0;
	if (max <= min)
		return (NULL);
	num_matrix = (int *)malloc(sizeof(int) * (max - min));
	while (i < (max - min))
	{
		num_matrix[i] = min + i;
		i++;
	}
	return (num_matrix);
}
